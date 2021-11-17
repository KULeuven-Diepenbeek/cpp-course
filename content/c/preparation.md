---
title: '0. Voorbereiding Thuis'
aliases:
    - /c/prep/
---

### Installaties

Volg de [installatieinstructies](/extra/installaties) en zorg ervoor dat de **basisvereisten** geïnstalleerd zijn:

- Een C compiler geïnstalleerd is (build essentials)
- Je vlot toegang hebt tot cmdline (Op Windows: met cmder, zie bovenstaande instructies)
- `git` geïnstalleerd is

### Controle

1. Controleer of git werkt door `git version` uit te voeren in cmdline.
2. Controleer of je compiler correct is geïnstalleerd door `gcc -v` uit te voeren, en `make -v`. 
3. Kopiëer het eerste voorbeeld in de tekst van hoofdstuk 1 ("vergelijkingen met Java") en probeer dit zelf te compileren in C met `gcc [bestand.c]`. Uitvoeren doe je door de binary in cmdline uit te voeren, standaard genoemd "a.out": `./a.out`.