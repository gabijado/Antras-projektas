#include "funkcijos.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <type_traits>
#include <numeric>

using namespace std;
using namespace std::chrono;

double mediana(vector<int> paz) {
    if (paz.empty()) return 0.0;
    sort(paz.begin(), paz.end());
    int n = static_cast<int>(paz.size());
    if (n % 2 == 0) return (paz[n/2 - 1] + paz[n/2]) / 2.0;
    return paz[n/2];
}

// Template: skaityti is failo
template <typename Container>
Container skaitytiIsFailo(const string& failo_pav) {
    Container studentai;
    ifstream fin(failo_pav);
    if (!fin) {
        cout << "Nepavyko atidaryti failo: " << failo_pav << endl;
        return studentai;
    }

    string header;
    getline(fin, header);

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
                std::istringstream ss(line);
        Studentas s(ss); // konstruktoriumi nuskaitomas studentas iš stringstream
        studentai.push_back(std::move(s));
    }

    fin.close();
    return studentai;
}


template vector<Studentas> skaitytiIsFailo<vector<Studentas>>(const string&);
template list<Studentas> skaitytiIsFailo<list<Studentas>>(const string&);

// Rodyti rezultatus
void rodytiRezultatus(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        return a.pavarde() < b.pavarde();
    });

    int pasirinkimas;
    cout << "Pasirinkite galutinio balo skaiciavimo metoda: \n";
    cout << "1 - Vidurkis\n2 - Mediana\n3 - Abu\n";
    cin >> pasirinkimas;

    cout << fixed << setprecision(2);
    if (pasirinkimas == 1) {
        cout << left << setw(15) << "Vardas" << "|" << setw(20)
            << "Pavarde" << "|" << setw(18) << "Galutinis (Vid.)" << endl;
        cout << string(55, '-') << endl;
        for (auto& s : studentai)
            cout << left << setw(15) << s.vardas() << "|" << setw(20)
            << s.pavarde() << "|" << setw(18) << s.galutinisVid() << endl;
    }
    else if (pasirinkimas == 2) {
        cout << left << setw(15) << "Vardas" << "|" << setw(20)
            << "Pavarde" << "|" << setw(18) << "Galutinis (Med.)" << endl;
        cout << string(55, '-') << endl;
        for (auto& s : studentai)
            cout << left << setw(15) << s.vardas() << "|" << setw(20)
            << s.pavarde() << "|" << setw(18) << s.galutinisMed() << endl;
    }
    else {
        cout << left << setw(15) << "Vardas" << "|" << setw(20)
            << "Pavarde" << "|" << setw(18) << "Galutinis (Vid.)"
            << "|" << setw(18) << "Galutinis (Med.)" << endl;
        cout << string(80, '-') << endl;
        for (auto& s : studentai)
            cout << left << setw(15) << s.vardas() << "|" << setw(20)
            << s.pavarde() << "|" << setw(18) << s.galutinisVid()
            << "|" << setw(18) << s.galutinisMed() << endl;
    }
}



template <typename Container>
void skirstytiIrRasyti(const Container& studentai, const string& konteinerio_pav, double& skirstymo_laikas, double& rasymo_laikas) {
    auto start_s = high_resolution_clock::now();
    Container vargsiukai, kietiakiai;
    for (const auto& s : studentai) {
        if (s.galutinisVid() < 5.0) vargsiukai.push_back(s);
        else kietiakiai.push_back(s);
    }
    auto end_s = high_resolution_clock::now();
    skirstymo_laikas = duration_cast<duration<double>>(end_s - start_s).count();

    auto start_w = high_resolution_clock::now();
    string failas_vargs = "vargsiukai_" + konteinerio_pav + ".txt";
    string failas_kiet = "kietiakiai_" + konteinerio_pav + ".txt";

    ofstream fout1(failas_vargs), fout2(failas_kiet);
    fout1 << left << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(18) << "Galutinis (Vid.)" << endl;
    fout2 << left << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(18) << "Galutinis (Vid.)" << endl;

    for (auto& s : vargsiukai) fout1 << left << setw(15) << s.vardas() << setw(20) << s.pavarde() << s.galutinisVid() << endl;
    for (auto& s : kietiakiai) fout2 << left << setw(15) << s.vardas() << setw(20) << s.pavarde() << s.galutinisVid() << endl;

    fout1.close(); fout2.close();
    auto end_w = high_resolution_clock::now();
    rasymo_laikas = duration_cast<duration<double>>(end_w - start_w).count();
}

// Strategija1
template <typename Container>
void skirstytiStrategija1(const Container& studentai, const string& konteinerio_pav, double& skirstymo_laikas, double& rasymo_laikas) {
    // identiška logika kaip skirstytiIrRasyti
    skirstytiIrRasyti(studentai, konteinerio_pav, skirstymo_laikas, rasymo_laikas);
}

// Strategija2 (perkelti ir istrinti)
template <typename Container>
void skirstytiStrategija2(Container& studentai, const string& konteinerio_pav, double& skirstymo_laikas, double& rasymo_laikas) {
    auto start_s = high_resolution_clock::now();

    if constexpr (std::is_same_v<Container, std::vector<Studentas>>) {
        auto it = stable_partition(studentai.begin(), studentai.end(), [](const Studentas& s) { return s.galutinisVid() < 5.0; });
        std::vector<Studentas> vargsiukai(studentai.begin(), it);
        studentai.erase(studentai.begin(), it);

        auto end_s = high_resolution_clock::now();
        skirstymo_laikas = duration_cast<duration<double>>(end_s - start_s).count();

        auto start_w = high_resolution_clock::now();
        ofstream fout1("vargsiukai_" + konteinerio_pav + ".txt");
        ofstream fout2("kietiakiai_" + konteinerio_pav + ".txt");

        for (auto& s : vargsiukai) fout1 << left << setw(15) << s.vardas() << setw(20) << s.pavarde() << s.galutinisVid() << endl;
        for (auto& s : studentai) fout2 << left << setw(15) << s.vardas() << setw(20) << s.pavarde() << s.galutinisVid() << endl;

        fout1.close(); fout2.close();
        auto end_w = high_resolution_clock::now();
        rasymo_laikas = duration_cast<duration<double>>(end_w - start_w).count();
    }
    else if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        std::list<Studentas> vargsiukai;
        for (auto it = studentai.begin(); it != studentai.end(); ) {
            if (it->galutinisVid() < 5.0) {
                vargsiukai.push_back(*it);
                it = studentai.erase(it);
            }
            else ++it;
        }

        auto end_s = high_resolution_clock::now();
        skirstymo_laikas = duration_cast<duration<double>>(end_s - start_s).count();

        auto start_w = high_resolution_clock::now();
        ofstream fout1("vargsiukai_" + konteinerio_pav + ".txt");
        ofstream fout2("kietiakiai_" + konteinerio_pav + ".txt");

        for (auto& s : vargsiukai) fout1 << left << setw(15) << s.vardas() << setw(20) << s.pavarde() << s.galutinisVid() << endl;
        for (auto& s : studentai) fout2 << left << setw(15) << s.vardas() << setw(20) << s.pavarde() << s.galutinisVid() << endl;

        fout1.close(); fout2.close();
        auto end_w = high_resolution_clock::now();
        rasymo_laikas = duration_cast<duration<double>>(end_w - start_w).count();
    }
}

// Strategija3 (optimizuota)
template <typename Container>
void skirstytiStrategija3(Container& studentai, const string& konteinerio_pav, double& skirstymo_laikas, double& rasymo_laikas) {

    if constexpr (std::is_same_v<Container, std::vector<Studentas>>) {
        auto start_s = high_resolution_clock::now();
        auto it = std::partition(studentai.begin(), studentai.end(), [](const Studentas& s) { return s.galutinisVid() < 5.0; });
        std::vector<Studentas> vargsiukai(studentai.begin(), it);
        studentai.erase(studentai.begin(), it);
        auto end_s = high_resolution_clock::now();
        skirstymo_laikas = duration_cast<duration<double>>(end_s - start_s).count();

        auto start_w = high_resolution_clock::now();
        ofstream fout1("vargsiukai_" + konteinerio_pav + ".txt");
        ofstream fout2("kietiakiai_" + konteinerio_pav + ".txt");

        for (auto& s : vargsiukai) fout1 << left << setw(15) << s.vardas() << setw(20) << s.pavarde() << s.galutinisVid() << endl;
        for (auto& s : studentai) fout2 << left << setw(15) << s.vardas() << setw(20) << s.pavarde() << s.galutinisVid() << endl;

        fout1.close(); fout2.close();
        auto end_w = high_resolution_clock::now();
        rasymo_laikas = duration_cast<duration<double>>(end_w - start_w).count();
    }
    else {
        
        skirstytiStrategija2(studentai, konteinerio_pav, skirstymo_laikas, rasymo_laikas);
    }
}


template void skirstytiStrategija1<vector<Studentas>>(const vector<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija1<list<Studentas>>(const list<Studentas>&, const string&, double&, double&);

template void skirstytiStrategija2<vector<Studentas>>(vector<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija2<list<Studentas>>(list<Studentas>&, const string&, double&, double&);

template void skirstytiStrategija3<vector<Studentas>>(vector<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija3<list<Studentas>>(list<Studentas>&, const string&, double&, double&);

// Generuoti failą (be pakeitimų)
void generuotiFaila(int kiekis) {
    string failo_pav = "studentai_" + to_string(kiekis) + ".txt";
    ofstream fout(failo_pav);
    fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde";
    for (int i = 1; i <= 5; i++) fout << setw(8) << ("ND" + to_string(i));
    fout << setw(8) << "Egz" << endl;
    for (int i = 0; i < kiekis; i++) {
        fout << left << setw(15) << ("Vardas" + to_string(i + 1)) << setw(15) << ("Pavarde" + to_string(i + 1));
        for (int j = 0; j < 5; j++) fout << setw(8) << (rand() % 10 + 1);
        fout << setw(8) << (rand() % 10 + 1) << endl;
    }
    fout.close();
    cout << "Sugeneruotas failas: " << failo_pav << endl;
}

void irasytiRezultatusReadme(double v_read, double v_split, double v_write, double l_read, double l_split, double l_write, const string& failo_pav) {
    ofstream fout("readme.md", ios::app);
    fout << "\n## Testo rezultatai (" << failo_pav << ")\n\n";
    fout << "| Konteineris | Nuskaitymas (s) | Skirstymas (s) | Rasymas (s) |\n";
    fout << "|--------------|----------------:|----------------:|-------------:|\n";
    fout << "| **vector** | " << fixed << setprecision(6) << v_read << " | " << v_split << " | " << v_write << " |\n";
    fout << "| **list**   | " << l_read << " | " << l_split << " | " << l_write << " |\n";
    fout << "\n";
    fout.close();
    cout << "Rezultatai irasyti i readme.md\n";
}
