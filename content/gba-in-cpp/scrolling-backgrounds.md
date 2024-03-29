---
title: '9. Scrolling backgrounds'
weight: 2
aliases:
    - /gba-in-cpp/labo-9/
---

Uit [hoofdstuk 4](/gba-in-c/labo-4) weten we hoe het VRAM van de GBA in elkaar steekt: het bestaat uit char en screen blocks. Character blocks 0 tot en met 3 vanaf `0x6010000` zijn gereserveerd voor achtergrond lagen: dat is in totaal meer geheugen dan voor sprites. De Gameboy Advance voorziet aparte registers om de 4 achtergrond lagen te configureren.

Voor sprites speelde een **tilemap** geen rol, voor grote achtergronden wel: het kost immers minder ruimte om de tile data apart op te slaan en in een map per tile te refereren naar die data. Achtergrond art is typisch iets herhalend: veel wolkjes, dezelfde soorten muren, plafond en vloeren. Uit hoofdstuk 4:

>Om tegen de GBA te zeggen welke tile op welke plaats in het scherm moet komen hebben we een **tilemap** nodig. Een tilemap kan wél heel groot worden en stelt letterlijk het "level" of de "map" voor, met op elke plaats in de 2-dimensionele lijst een referentie naar een tile. Zie [Metroid Level voorbeeld](https://www.coranac.com/tonc/text/regbg.htm).

## Een uitbreiding op de abstractielaag

We introduceren de volgende nieuwe concepten in ons domein model:

{{<mermaid>}}
graph TD;
  A{Palet}
  B{Achtergrond}
  C[AchtergrondLaag0]
  D[AchtergrondLaag1]
  E[AchtergrondLaag2]
  F[AchtergrondLaag3]
  G[Voorgrondpalet]
  H[Achtergrondpalet]
  A --> G
  A --> H
  B --> C
  B --> D
  B --> E
  B --> F
{{< /mermaid >}}

Waarbij de diamant blokken abstracte klassen voorstellen.

### Het achtergrondpalet

Juist zoals het voorgrondpalet (adres `0x5000200`) is er maar één palet voor de achtergrond aanwezig bestaande uit 256 kleuren. Om hier mee om te gaan heb je een paar mogelijkheden:

1. Per verwisseling van achtergrond persisteer je een nieuw palet in het geheugen.
2. Elke achtergrondlaag deelt hetzelfde palet.

Het adres voor het achtergrondpalet is `0x5000000`.

### Het achtergrond register

De GBA heeft net zoals het `OAM` een aantal flags in de vorm van bits nodig per achtergrond om te configureren in welk VRAM de imageset steekt en hoe groot het is. Zie ook weer [gbatek specificaties](https://problemkaputt.de/gbatek.htm). De belangrijkste flags leven vanaf bit 8 (screen block naar tilemap) en 2 (char block naar imageset).

De adressen voor elk register zijn:

1. `0x4000008` voor BG0
2. `0x400000a` voor BG1
3. `0x400000c` voor BG2
4. `0x400000e` voor BG3

De gewenste achtergronden moeten net als de video mode in het algemeen controle register aangezet worden:

```C
#define MODE0 0x00
#define MODE1 0x01

#define BG0_ENABLE 0x100
#define BG1_ENABLE 0x200
#define BG2_ENABLE 0x400
#define BG3_ENABLE 0x800

display_control = MODE0 | BG0_ENABLE;
```

Mode 0 hebben we later nodig om de achtergrond te laten scrollen. Mode 0, 1 en 2 zijn drie mogelijke "tile" (sprite) modes.

### Het tilemap adres

Tilemaps leven net zoals de rest wat tiles aanbelangt in het VRAM. Kies een geheugen plaatsje dat niet in beslag genomen wordt door je eigenlijke tile data.

Een tilemap ontwerpen in notepad is snel vervelend en geeft geen visuele feedback. Er zijn tools op [ROMHacking.net](https://www.romhacking.net/utilities/463/) die (al dan niet specifiek per spel) het ontwerpen vergemakkelijken. De eenvoudigste is [GBA Tile-editor](https://github.com/IanFinlayson/gba-tileeditor):

<img src="/img/teaching/cpp/tileeditor.png" />

(Voor Windows gebruikers: [Wingrit](https://www.coranac.com/man/grit/html/wingrit.htm)) <br/>
De Onderste image is de **tileset**. Selecteer één tile en klik dan op een plaats om die tile op de map te doen verschijnen. De editor exporteert de map als een `unsigned short[]`:

```C
const unsigned short map [] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0012, 0x0014, 0x0014, 0x0015, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0008,
    0x0009, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001d,
};
```

De waardes zijn referenties naar de tiles in de tileset met `0x0000` als éérste tile linksboven (de blauwe lucht). Dit kopiëren we op dezelfde manier (`memcpy`) als de tileset op een ongebruikte plaats in het VRAM.

### De map laten scrollen

Een tilemap kan best groot worden, en bijna alle 2D platformers of top-down adventure spellen op de GBA hebben een achtergrond die "scrollt". Herinner je het Castlevania voorbeeld uit [labo 8](/gba-in-cpp/labo-8):

<img src="/img/teaching/cpp/aria-of-sorrow.gif" style="width: 100%" class="bordered" />

Je kan duidelijk zien dat de achtergrond niet alleen bestaat uit verschillende lagen, maar ze ook scrollt afhankelijk van de positie van Soma, het hoofdpersonage. Scrollen in X of Y richting is heel eenvoudig en vereist - verrassing! - manipuleren van een register: van `0x4000010` tot `0x400001e` (+2, beginnen met bg0 x, bg0 y, bg1 x, ...).

Dit is een _write-only_ register: de X en Y scroll waardes zal je zelf in een variabele moeten bijhouden. Vergeet dit niet te doen na een _VBLANK_ om _tearing_ te vermijden.

## De toepassing in C++

De verschillende lagen zijn een ideaal slachtoffer om in C++ concepten als templates of abstract klassen toe te passen. De enige verschillen zijn immers de adressen in in het RAM.

Om geen random waardes te gebruiken als charblock of screenblock om de tileset en tilemaps van elke achtergrond in weg te schrijven hebben we nood aan een "geheugen beheerder" concept:

{{<mermaid>}}
graph TD;
  A[MemoryManager]
  Base{BaseBGLayer}
  B0[BGLayer0]
  B1[BGLayer1]
  B2[BGLayer...]
  B0 --> Base
  B1 --> Base
  B2 --> Base
  C[BackgroundPalette]
  D[Tileset]
  E[Tilemap]
  F["Scroll value(x,y)"]
  Base --> D
  Base --> E
  Base --> F
  Base -.-> C
{{< /mermaid >}}

De memory manager en het achtergrondpalet zijn gedeeld tussen de backgroundlayer instanties. Uit het schema van [labo 8](/gba-in-cpp/labo-8) weten we dat een `GBA` klasse nodig is die de memory manager, achtergrondlagen en paletten aanmaakt en gebruikt. <br/>
In totaal hebben we de volgende gegevens nodig:

De klasse `Palette` met members:

- `unsigned short data[X]` (komt uit tile generator)

De **abstracte** klasse `BaseBGLayer` met members:

- `void scroll(int x, int y)`
- `int scrollX, scrollY`
- `unsigned short tileset[X]` (komt uit tile generator)
- `unsigned short tilemap[X]` (komt uit tile generator)
- `Palette palette`
- `unsigned short address`

De concrete implementatie van de base klasse `BGLayer0` met als juiste adres waarde, doorgegeven via de constructor parameter.

De klasse `MemoryManager`, met members:

- `void save(BaseBGLayer bglayer)` (bewaar data in GBA geheugen)

De klasse `GBA`, met members:

- `MemoryManager manager`
- `void initialize()` (maak nodige instanties aan en roep bewaar op)
- `void run()` (main game loop)
- `void vblank()`

De file `main.cpp` met een `main()` functie die de `GBA` klasse activeert.

Vergeet niet te denken aan:

- Accesss modifiers en getters/setters indien nodig.
- Pointers! Wel/niet/smart pointers/niet?

## <a name="oef"></a>Labo oefeningen

1. Ontwerp een minimale standaard C++11 applicatie (zonder GBA) die bovenstaande modellen bevat en 1 achtergrondlaag 'toont' (door in de main functie de juiste andere functies aan te spreken, die nog niets doen behalve een simpele `cout`). De focus ligt op het juiste OO ontwerp.<br/>De oefening is geslaagd als bovenstaande methodes zijn geïmplementeerd. 
2. Converteer bovenstaande standaard C++11 toepassing naar een GBA applicatie door cross-compile CMake flags te gebruiken. Baseer je op de [CMakeLists.txt](https://github.com/wgroeneveld/gba-sprite-engine/blob/master/CMakeLists.txt) van het project. <br/>Gebruik voor de achtergrond [deze tileset](/teaching/cpp/labo-9-tileset.png). Nu gaan we de namaak functies effectief implementeren. Haal de tileset door de png2gba tool die we kennen uit labo 8. Verzin je eigen tilemap.
3. Laat de tilemap scrollen met het GBA keyboard (left, right: -x, +x, up, down: -y, +y). Scrollen wordt door de hardware ondersteund dus gaat héél snel: vertraging inbouwen kan door de CPU wat bezig te houden: `for(int i = 0; i < 4567; i++){}`.

## Denkvragen

1. Scrollen gebeurt niet altijd. Kijk nog eens goed naar Soma als hij naar links beweegt richting de deur. Hoe kunnen we dit implementeren - gegeven een karakter in het midden van het scherm, wanneer starten we en wanneer stoppen we met scrollen?
2. Op welke manier kan je de nadelen van het gedeelde achtergrondpalet minimaliseren?
