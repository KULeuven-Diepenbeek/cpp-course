---
title: Hoe werk ik samen aan een project?
---

Samenwerken aan een programmeeropdracht kan op verschillende manieren, maar de ene oplossing is de andere niet. Hieronder volgt een kort overzicht van veel gebruikte tools om virtueel samenwerken te vergemakkelijken. 

## Samen ontwerpen

Goede afspraken maken goede vrienden---dat geldt ook voor medestudenten binnen één project. Afspraken maken kan uiteraard via **Discord** of **Slack**. 

Die systemen zijn echter erg _vluchtig_: om een project aan te pakken moet je de opdracht opknippen in **kleine taakjes** en die verdelen, waarbij iedereen zijn eigen verantwoordelijkheid heeft. Hoe deel je die taken? Hoe kan je laten zien welke taak klaar is en met welke jij bezig bent? 

Daarvoor is Discord niet genoeg---je hebt een project planner nodig. De eenvoudigste daarvan is **Trello**: https://trello.com/ die een mooi overzicht geeft over TODO - DOING - DONE items:

![](https://d2k1ftgv7pobq7.cloudfront.net/meta/p/res/images/spirit/product/89d378b845766a8f0c48e955336266f8/board.png)

Ook hier zijn alternatieven voor (Basecamp, Workzone, ProofHub, ...) Je kan steeds collaboratie sessies inlassen en samen tekenen via tools als https://www.anondraw.com/collab of natuurlijk gewoon Zoom/Google Meet en de desktop sharen. 

## Code delen

### 1. Code doorsturen naar elkaar

Mailtje opstellen, code in attach, en versturen maar. Dit is verreweg de eenvoudigste manier om digitaal **bestanden** te delen, maar als het op broncode aankomt, kom je al snel in de problemen:

- Sommige mailservers denken dat je virussen verstuurt en blokkeren bijlages. 
- Je andere teamleden sturen óók mailtjes met dezelfde bestanden---welke is nu de laatste versie? 
- Je andere teamleden wijzigen constant dezelfde bestanden---welke is nu de laatste versie? 

**Tijdelijke oplossing**: revisies van broncode hernoemen. Bijvoorbeeld: `spel.java` wordt `spel-seppe1.java` of `spel-20211210.java`. Je merkt het al: dit wordt ook snel een soepje en lost de essentie van het probleem van de eindeloze bijlages niet op. 

### 2. In de cloud

Deel de broncode via een virtueel gedeelde map in Google Drive of Dropbox. Deze systemen geven ook aan wanneer bestanden door anderen worden gewijzigd. 

Dit is nog steeds niet ideaal en geeft vaak conflicten als je in dezelfde bestanden werkt als je collega's. **Afspraken maken** wie wat doet in welke file doet wonderen! 

### 3. In live code editing omgevingen

Maak allemaal accounts aan op systemen zoals https://replit.com/. Daar kan je live code zien wijzigen door collega's, samen live coden in één file, en zit er nog eens voice streaming, desktop sharing, ... in. 

![](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fi.ytimg.com%2Fvi%2F5glKXbCFOpE%2Fmaxresdefault.jpg&f=1&nofb=1)

Bovenstaande screenshot toont een live Repl.it Java sessie (zie YouTube voor video tutorials).

Desktop sharing oplossingen zijn er genoeg, maar `repl.it` blinkt uit omdat het een programmeer-specifieke omgeving is. 

Een nadeel is dat compileren met bijvoorbeeld JavaFX of andere libraries moeilijk gaat omdat dat allemaal op een andere server gebeurt. In dat geval kan je nog steeds code daar samen schrijven, dat kopiëren, en lokaal verder compileren met de juiste versie van de JDK. 

### 4. Source control

Veruit de beste manier om code te delen is via een **code repository**: dat is een database waar de broncode wordt opgeslagen waar jullie allemaal tegelijkertijd aan kunnen werken. De populairste manier is tegenwoordig `git`. Een gratis account via https://github.com/. Hoe werkt zoiets? Er is een "getting started guide" op https://docs.github.com/en/get-started/.

Merk op dat dit opzetten enige tijd kost: er zijn nieuwe programma's om te installeren, commando's om te leren gebruiken, en protocollen om je aan te houden. Als dit je eerste softwareproject is in het eerste jaar is dit niet de beste optie. Denk hier wel aan in je tweede jaar. 

Voor de Electronica-ICTers of Informatica-ingenieurs is dit verplichte kost. 


