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

studentai1000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      30.1468        5.40586        6.01212
List        27.2391        1.6608         6.29654

studentai10000000.txt
Konteineris Nuskaitymas    Skirstymas     Rasymas
       -----------------------------------------------
Vector      0.439026       6.54832        0.0811908
List        0.392605       0.0215299      0.0928069

## 2 strategija
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

## Palyginimas su V1.1 rezultatais
Abiejų versijų programos testuotos su tais pačiais duomenimis ir sąlygomis:
1. Naudotas vektoriaus (std::vector) konteineris ir list (std:: list) konteineris.
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
3. Klasės realizacija pasirodė efektyvesnė didelių duomenų kiekių apdorojimui dėl geresnės kapsuliacijos ir optimizuojamo metodų iškvietimo.

## cin ir cout realizacija

## Įvesties failo (pvz.: 'studentai1000.txt') formatas: 
Pirmoje eilutėje yra antraštė: Vardas Pavarde ND1 ND2 ND3 ND4 ND5 Egz;

Kiekviena tolesnė eilutė — vienas studentas, pavyzdys: Vardas1 Pavarde1 7 8 9 6 10 8, kur 7..10 — namų darbų balai (5 ND), paskutinis skaičius — egzamino balas.

### Įvestis ir išvestis (perdengti / overloaded metodai)

## 1. operator>> (įvestis)**  
Įgyvendinta 'Studentas' klasėje ('studentas.cpp'):
std::istream& operator>>(std::istream& is, Studentas& s) {
    s.nd_.clear();
    is >> s.vardas_ >> s.pavarde_;
    int x;
    for (int i = 0; i < 5; i++) { is >> x; s.nd_.push_back(x); }
    is >> s.egz_;
    s.skaiciuotiGalutinius();
    return is;
}

Šis operatorius leidžia skaityti studentą tiek iš konsolės (std::cin >> s), tiek iš failo (std::ifstream f("..."); f >> s;).
Po skaitymo iškart apskaičiuojami galutiniai balai (skaiciuotiGalutinius()).

## 2. operator<< (išvestis)
Įgyvendinta 'Studentas' klasėje ('studentas.cpp'):
std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << std::left << std::setw(15) << s.vardas_ << std::setw(20) << s.pavarde_
       << std::setw(12) << std::fixed << std::setprecision(2) << s.galutinisVid_
       << std::setw(12) << std::fixed << std::setprecision(2) << s.galutinisMed_;
    return os;
}

Leidžia gražiai atvaizduoti studentą konsolėje (std::cout << s;) arba rašyti į failą su ofstream (out << s;).

## 3. Rankinė įvestis
Rankinė įvestis realizuota main() - naudojamas getline / cin >> norint įvesti vardą, pavardę, ND ir egzaminą. Po kiekvieno įrašo yra sukuriamas Studentas objektas ir pridedamas į kontenerį.

## 4. Automatinė generacija
Funkcija generuotiFaila(int kiekis) sugeneruoja failą studentai_<kiekis>.txt. Ji naudojama testams kurti.

## 5. Išvestis į failą
Skirstymo funkcijos (skirstytiStrategija*) rašo du failus: geri.txt ir blogi.txt. Taip pat rezultatai kiekvieno bandymo įrašomi į readme.md per irasytiRezultatusReadme.

## Ekrano nuotraukos
![alt text](image-2.png)
Ekrano nuotraukoje matomas pagrindinis meniu po programos paleidimo

![alt text](image-3.png)
Ekrano nuotraukoje matomas pirmas pasirinkimas, apskaičiuoti rezultatai ir pateikta rezultatų lentelė.

![alt text](image-4.png)
Ekrano nuotraukoje matomas antras pasirinkimas, apskaičiuoti rezultatai ir pateikta rezultatų lentelė.

![alt text](image-5.png)
Ekrano nuotraukoje matomas trečias pasirinkimas pasirinkus failą 'studentai1000.txt', apskaičiuoti rezultatai ir pateikta rezultatų lentelė.

![alt text](image-6.png)
![alt text](image-7.png)
Ekrano nuotraukose matomas ketvirtas pasirinkimas ir sugeneruoti failai kompiuteryje.

![alt text](image-8.png)
Ekrano nuotraukoje matomas penktas pasirinkimas pasirinkus failą 'studentai1000.txt', 1 strategiją. Apskaičiuoti rezultatai ir pateikta rezultatų lentelė.

![alt text](image-9.png)
Ekrano nuotraukoje matomas penktas pasirinkimas pasirinkus failą 'studentai1000.txt', 2 strategiją. Apskaičiuoti rezultatai ir pateikta rezultatų lentelė.

![alt text](image-10.png)
Ekrano nuotraukoje matomas penktas pasirinkimas pasirinkus failą 'studentai1000.txt', 3 strategiją. Apskaičiuoti rezultatai ir pateikta rezultatų lentelė.

## CMake įdiegimas Windows naudojant .msi paketą
1. Atsisiuntimas
   1. Reikia įeiti į oficialų CMake puslapį: https://cmake.org/download/
   2. Pasirinkti Windows x64 Installer (.msi) versiją.
2. Diegimas
   1. Paleisti atsisiųstą .msi failą.
   2. Spausti Next visuose languose.
   3. Svarbu: pasirinkti "Add CMake to the system PATH for all users" arba "for current user".
3. Baigimas
   1. Spauskite Finish, kai diegimas baigtas.
   2. Atidarykite naują PowerShell langą.
   3. Patikrinkite diegimą įvedę: cmake --version

## CMakeLists.txt failas
CMakeLists.txt failas turėtų atrodyti taip:

cmake_minimum_required(VERSION 3.25)

project(Studentu_programa)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(Studentu_programa ${SOURCES})

## Į PowerShell reikia rašyti taip:
cmake CMakeLists.txt
cmake --install .
cmake -- build .
copy src\studentai_*.txt Debug\Studentu_programa
cd Debug\
Studentu_programa.exe
pause

## Pademonstruota, kad realizuota abstrakti aibė Žmogus
int main() {
	// Zmogus z; užkomentuota, nes Zmogus yra abstrakti klasė
    srand(time(0));
    int veiksmas;
}

Šioje dalyje 'Zmogus z' užkomentuotas, nes Zmogus yra abstrakti klasė. Jei komentarą nuimsiu, programa rodys klaidas.

![alt text](image.png)
Ekrano nuotrauka, kurioje matoma klaida, kai 'Zmogus z' nėra užkomentuota.

