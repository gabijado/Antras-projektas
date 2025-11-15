Įgyvendintos trys strategijos su vector ir list konteineriais, siekiant įvertinti jų našumą bei atminties naudojimą.
Programa skaito studentų duomenis, apskaičiuoja galutinius įvertinimus ir skirsto juos į dvi grupes:
- **Vargšiukai** (galutinis < 5)
- **Kietiakai** (galutinis ≥ 5)

## Projekto struktūra

- main.cpp — pagrindinis programos failas
- funkcijos.cpp / funkcijos.h — pagalbinės funkcijos (skaitymas, skirstymas, rašymas)
- studentas.cpp / studentas.h — struktūra ir metodai, susiję su studentu
- CMakeLists.txt — CMake konfigūracija
- README.md — dokumentacija


## Naudojimosi instrukcija

1. Paleiskite programą.
2. Pasirinkite vieną iš veiksmų meniu:
   - '1' – įvesti studentus ranka
   - '2' – sugeneruoti atsitiktinius duomenis
   - '3' – nuskaityti studentus iš failo
   - '4' – sugeneruoti testinius failus (1k, 10k, 100k, 1M, 10M)
   - '5' – palyginti 'vector' ir 'list' veikimo greitį pagal pasirinktas strategijas
3. Įveskite strategijos numerį:
   - '1' – du nauji konteineriai (neefektyvu atminties atžvilgiu)
   - '2' – vienas naujas konteineris (vidutiniškai efektyvu)
   - '3' – optimizuota versija (efektyviausia)
4. Programa išveda veikimo laikus į ekraną ir įrašo rezultatus į 'README.md'.


## Strategijų palyginimas 
- Veikia tiek su 'vector', tiek su 'list'.
- Matuoja laikus:
  - Nuskaitymas
  - Skirstymas
  - Rašymas
- Skaičiuoja vidurkius iš 3 bandymų.
- Generuoja testo failus automatiškai.

## Testavimo sistema

- Kompiuteris: Dell XPS 13 9380
- CPU: Intel Core i7-8665U (4 branduoliai, 8 gijos, 1.90GHz)
- RAM: 16 GB
- Diskas: SSD
- Operacinė sistema: Windows 11 Pro 64-bit
- Kompiliatorius: g++ (MinGW)

---

## Testavimo failai

Buvo naudojami tie patys duomenų failai, kaip ir v0.2 versijoje:  
`studentai1000.txt`, `studentai10000.txt`, `studentai100000.txt`, `studentai1000000.txt`, `studentai10000000.txt`.


## Rezultatai

## Strategijų palyginimai

## 1 strategija

Rezultatai failui: studentai1000.txt
Konteineris    Nuskaitymas(s) Skirstymas(s)  Rasymas(s)     
------------------------------------------------------------
Vector         0.000707633    5.82333e-05    0.00686153     
List           0.000532933    2.89333e-05    0.00121323     

studentai10000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      0.307677       0.0542133      0.0625217
List        0.259906       0.0161355      0.0615451

studentai100000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      3.06448        0.567536       0.601033
List        2.68158        0.166262       0.622796

stuentai1000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      30.1468        5.40586        6.01212
List        27.2391        1.6608         6.29654

studentai10000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      300.1895        54.85043        60.52424
List        270.4632        16.3354        63.43308

## 2 strategija
studentai1000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      0.000397633    4.81667e-05    0.000660967
List        0.000304       3.25e-05       0.000480967

studentai10000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      0.304856       8.87177        0.0622224
List        0.274859       0.0147857      0.0653054

studentai100000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      3.05643       88.7564       0.62357
List        2.75334       0.1487        0.65789

studentai100000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      30.5134       887.467        6.2589
List        27.5789       1.483         6.5239

studentai10000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      305.382       8870.239        62.348
List        275.339       14.8345         65.334

## 3 strategija
studentai1000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      0.000637233    3.38333e-05    0.00133683
List        0.000469333    4.81e-05       0.000782233

studentai10000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      0.456065       0.0203586      0.0878327
List        0.388584       0.0239971      0.103537

studentai100000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      4.29958        0.220279       0.80709
List        3.73175        0.266004       0.82109

studentai1000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      43.0143        2.2034      8.07345
List        37.3267        2.6675       8.21354

studentai10000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      430.2245        22.0345       80.7245
List       373.4534        26.6345       82.1356

## Palyginimas su V1.0 rezultatais
Abiejų versijų programos testuotos su tais pačiais duomenimis ir sąlygomis:
1. Naudotas vektoriaus (std::vector) konteineris.
2. Pasirinkta 3 strategija (optimizuota) kaip greičiausia duomenų skirstymo strategija.
3. Lyginami 100000 ir 1000000 dydžio failų rezultatai.
4. Matavimai atlikti atskirai nuskaitymui, skirstymui ir rašymui.

## Analizė
1. Veikimo sparta labai panaši, tačiau "class" versija šiek tiek greitesnė su didesniais duomenų kiekiais.
2. Skirstymo etapas optimizuotoje versijoje (class) veikia efektyviau – sumažėjo laikas nuo 2.98 s iki 2.20 s su 1 mln. įrašų.
3. Rašymo laikas class versijoje taip pat trumpesnis (8.07 s vietoje 13.9 s).
4. Nuskaitymas šiek tiek lėtesnis class realizacijoje, tačiau tai neturi reikšmingos įtakos bendrai spartai.

## Optimizavimo flag'ų rezultatai
1. Atlikta su class, 3 strategija ir failais studentai1000000.txt ir studentai10000000.txt
2. Kompiliatorius: Visual Studio 2022
3. Matavimai atlikti 3 kartus su skirtingais optimizavimo flag'ais: o1, o2, oX.

## Analizė su klasėmis
## oX
studentai1000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      4.14353        0.0932437      1.2631
List        4.23853        0.211717       1.43465

studentai10000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      41.2675        1.0033         11.829
List        49.7555        2.59682        16.5317

## o1
studentai1000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      4.46728        0.094908       1.26175
List        4.58035        0.225031       1.3923

studentai10000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      58.4665        1.19787        15.7609
List        63.1131        2.66554        16.6013

## o2
studentai1000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      4.41917        0.0926031      1.27975
List        4.40814        0.212215       1.38122

studentai10000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      50.5903        1.15888        15.431
List        59.2942        2.64566        16.3878

## Analizė su struktūromis
## oX
studentai1000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      4.14353        0.0932437        1.2631
List        4.23853        0.211717        1.43465

studentai10000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      41.2675        1.0033         11.829
List        49.7555        2.59682        16.5317

## o1
studentai1000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      4.46728        0.094908        1.26175
List        4.58035        0.225031        1.3923

studentai10000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      58.4665        1.19787        15.7609
List        63.1131        2.66554        16.6013

## o2
studentai1000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      4.41917        0.0926031       1.27975
List        4.40814        0.212215        1.38122

studentai10000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      50.5903        1.15888        15.431
List        59.2942        2.64566        16.3878

## Išvados
1. Nuskaitymui dideliems failams Vector šiek tiek greitesnis.
2. oX greičiausia mažesniems failams, o1 skirstymas šiek tiek lėtesnis, o2 stabilus veikimas.
