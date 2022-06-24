---
title: 'Project opdracht'
date: 2020-10-05
---

Laatst geupdate voor **Academiejaar 2021 - 2022**.

## Project opdracht---tweede kans

**Deadline**: maandag 22/08/2022, om 12u 's middags.

Dezelfde **minimumvereisten** gelden als de opdracht in eerste kans. Werk met een volledig _nieuwe_ Github repository, en vertrek opnieuw vanaf de `gba-sprite-engine`. Geregistreerde tijd bijhouden is niet meer nodig. 

De opdracht is _niet_ vrij te kiezen. Het criteria 'originaliteit' (zie onder) zal beoordeeld worden op de manier waarop je deze vaste opdracht hebt ingekleurd. De opdracht is _individueel_ en niet in groep zoals eerste kans. De mondelinge projectverdediging zal ook individueel verlopen. 

#### Opdracht beschrijving

Ontwerp een **Mario Party kloon**. In dit _bordspel_ gaan spelers op een klassieke manier het bord rond om punten te verzamelen. De structuur van het bord is gelijkaardig aan een Ganzenbord spel. Elke plek waar de speler zijn of haar pion terecht komt, brengt een bepaalde actie met zich mee. In Mario Party wordt er meestal een minigame gespeeld, dat indien gewonnen punten oplevert. Hier is een video van de officiële GBA implementatie:

{{< youtube dvC4hgoNOfE >}}

<br/>
Wat moet minimaal aanwezig zijn?

* Een titelscherm.
* Een bord. De layout maak je zo simpel of complex als je zelf wenst. 
* Een pion die de speler voorstelt. De mogelijkheid om vakjes te verschuiven. 
* Tenminste één (zeer eenvoudig) minigame. De inhoud mag je zelf bepalen. 
* Zichtbaarheid van de score. 

Wat is optioneel (maar levert extra punten op)?

* Extra spelers in de vorm van AI. 
* Extra minigames. 
* Keuze van de pion.
* Animaties en geluid.

Inleverformaat op dezelfde manier als in de eerste kans. 

---

## Project opdracht---eerste kans

**Deadline**: donderdag 27/01/2022, om 12u 's middags.

---

Om jullie recent opgedane object-geörienteerde technieken te toetsen gaan jullie een **GBA spel** ontwerpen en ontwikkelen in C++11. De focus van de opdracht ligt niet op correcte low-level IO mapping maar op kritisch denken en testen zoals gezien in [hoofdstuk 7](/cpp/labo-7). Uiteraard komen zowel pointers en GBA programming technieken van de vroegere hoofdstukken, als C++ class inheritance en abstractie lagen uit de latere hoofdstukken aan bod. 

Vertrek vanuit de [gba-sprite-engine](https://github.com/wgroeneveld/gba-sprite-engine/) library op <i class="fab fa-github-square"></i> Github door een <i class='fa fa-code-fork'></i> **fork te nemen** met de knop rechtsboven:

![](/img/fork_button.jpg)

Dit kopiëert de repository naar je eigen GitHub account, met url `https://github.com/uw-gebruikers-naam/gba-sprite-engine/`. Lees in de GitHub docs [hoe een fork te nemen van een repo](https://docs.github.com/en/get-started/quickstart/fork-a-repo).

Door te starten vanuit dat project bespaar je veel werk met een nieuw GBA project op te zetten en alle IO adressen opnieuw te mappen. Er is een README voorzien voor meer info. De engine gebruikt [Tonc](https://www.coranac.com/tonc/text/toc.htm) achterliggend. 

Wat voor soort spel het moet zijn laen we aan jullie over. Het spreekt voor zich dat complexiteit (en originaliteit!) mee in rekening gebracht wordt: zie evaluatiecriteria. Inspiratie nodig? 

* [GBA Projecten vorige jaren videos](/cpp-course/hoorcolleges/)
* [Top 10 Gameboy Advance games in 10 minutes](https://www.youtube.com/watch?v=2-R-F-A48FI)
* [25 Best Gameboy Advance games Ever](http://www.denofgeek.com/us/games/game-boy-advance/256070/25-best-game-boy-advance-games-ever)

Zie ook onderaan, projecten van vorige jaren.

Werk bij voorkeur in **groepen van 2** of indien oneven 3. 


## Minimumvereisten

Lees dit goed na: projecten die niet voldoen aan de volgende vereisten zullen niet geëvalueerd worden. 

1. De code leeft in een repository op Github onder jullie username met de [MIT](https://help.github.com/articles/licensing-a-repository/#disclaimer) license. 
2. Je vertrekt vanuit `gba-sprite-engine` - zie hierboven. Daarbij blijf je binnen GBA `MODE0` en werk je met sprites. C++11 is hiermee ook een vereiste.
3. Indien je je baseert op andere bestaande code doe je aan **bronvermelding**! Plagiaat wordt zeer ernstig bestraft. 
4. Je project moet uiteraard minstens compileren.
5. Je repository `README.md` bevat een kleine functionele beschrijving van jullie spel.
6. Naast de functionele beschrijving upload je ook een schets van je **domein model**, gepaard met verklarende tekst. 

Het is **niet** de bedoeling om je te baseren op één van de engine demo's en die simpelweg verder uit te werken. Dat biedt onvoldoende uitdaging en originaliteit. 

{{% notice warning %}}
Omdat als vereiste elk project op Github leeft kunnen jullie elkaar's repository, of die van vorige jaren, ook raadplegen. Of jullie daar gebruik van willen maken laten we aan jullie over. <br/>Merk op dat _zonder bronvermelding_ kopiëren, of _het ontwerp van het spel_ en code volledig overnemen, aanschouwd wordt als plagiaat. Als het onderwijsteam vermoedt dat er zonder nadenken een kopie genomen wordt van een bestaand spel zal dit resulteren in een onvoldoende.
{{% /notice %}}

## Evaluatiecriteria

Punten worden op twee keer op `/20` gegeven. Eenmalig een globaal cijfer, eenmalig een genormaliseerd cijfer, rekening houdend met de volgende subcriteria en gewichten:

1. `O.4` Design<br/>
Hoe is je Object-Oriented design en domein model?<br/>
<span style="color: lightgrey; font-style: italic;">Hoge score: duidelijk herkenbare objecten, terug te vinden in domein model, met gescheiden verantwoordelijkheden.<br/>Lage score: Alles in enkele objecten gestopt, onduidelijk wie wat doet, nauwelijks of geen model. </span>
2. `O.5` Clean Code<br/>
Hoe leesbaar is je code?<br/>
<span style="color: lightgrey; font-style: italic;">Hoge score: eenvoudig begrijpbare variabelen, methodes, klassen. <br/>Lage score: Te veel herlezen is nodig om te begrijpen wat er gebeurt.</span>
4. `0.4` Complexiteit <br/>
Hoe moeilijk heb je het gemaakt?<br/>
<span style="color: lightgrey; font-style: italic;">Hoge score: gekozen voor een uitdaging in de plaats van een eenvoudige implementatie. <br/>Lage score: Het pad met de kleinste weerstand bewandeld, de lat te laag gelegd.</span>
5. `0.3` Originaliteit <br/>
Hoe origineel en creatief is je idee?<br/>
<span style="color: lightgrey; font-style: italic;">Hoge score: een origineel idee uitgewerkt in plaats van een kloon van een standaard 2D platformer.<br/>Lage score: gekozen voor een weinig inspirerend ontwerp, alles gebaseerd op iets bestaand inclusief sprites. </span>
6. `0.2` GBA UI <br/>
Hoe uitgebreid is de multimedia presentatie?<br/>
<span style="color: lightgrey; font-style: italic;">Hoge score: alle UI/geluid technieken uitgebreid toegepast: tiles, sprites, scrolling backgrounds, ...<br/>Lage score: Weinig tot geen animatie/backgrounds, eentonig ontwerp. </span>

Waarbij beide cijfers herleid worden tot één.<br/>
De tekst in het lichtgrijs dient ter ondersteuning bij het geven van een quotering op dat bepaald criterium, waar concrete voorbeelden met een _lage_ en _hoge_ score zijn uitgewerkt. 

## Inleverformaat

Datum te bepalen, evenals verdedigingsdata.

* Je mailt je github repository URL door, samen met een gecompileerde `.gba` ROM die je zelf getest hebt. 
* De gecompileerde ROM upload je ook naar Toledo.
* Er hangt ook een kleine verdediging aan vast zodat we kunnen valideren of je voldoende kennis hebt over de code van je eigen spel. We spelen samen het spel en overlopen de code, waarbij er geantwoord wordt op enkele vragen die invloed uitoefenen op het globaal cijfer. 

## Praktische tips

* Begin bij het begin: werk een concept uit **op papier** en teken dan een ruw model uit. Dit model is onderhevig aan verandering naargelang de ontwikkeling. Vergeet het finale model niet toe te voegen aan de `README`.
* **Hou het simpel** en werk gradueel iets complexer uit. Wees niet te overmoedig: een zeer goede implementatie scoort hoger dan een slappe complexe.
* Denk voor stukjes met logica eerst aan unit testen. Een test die slaagt helpt je al een heel eind verder. 
* Test je spel tijdig op de mGBA emulator, of in de GBA zelf met een flashcard (uit te lenen bij de lesgever). 
* Gebruik het voordeel van git: check in op regelmatige tijdstippen, zelfs meerdere keren per dag, wanneer iets werkt. Op die manier bespaar je jezelf een hoop werk als er iets teruggedraaid moet worden. 
* Denk aan concepten die je geleerd hebt in andere programmeervakken, zoals Model-View-Controller (MVC) in "Software ontwerp in Java". [Separation of Concerns](https://en.wikipedia.org/wiki/Separation_of_concerns) is ook in C++ van toepassing. 

## Projecten van vorige jaren

Onderstaande filmpjes geven een beeld van wat mogelijk is binnen de tijdspanne van dit vak. Merk op dat niet elk project evenveel punten scoorde. 

<iframe title="vimeo-player" src="https://player.vimeo.com/video/392922578" width="640" height="428" frameborder="0" allowfullscreen></iframe>

<iframe title="vimeo-player" src="https://player.vimeo.com/video/314203871" width="640" height="428" frameborder="0" allowfullscreen></iframe>

