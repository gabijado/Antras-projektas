#include "funkcijos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// ------------------ Funkcijų aprašymai ------------------

// Sugeneruoti failą su studentais
void generuotiFaila(int kiekis) {
    string fail = "studentai_" + to_string(kiekis) + ".txt";
    ofstream fout(fail);

    fout << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 Egz\n";

    for (int i = 0; i < kiekis; i++) {
        fout << "Vardas" << i + 1 << " Pavarde" << i + 1 << " ";
        for (int j = 0; j < 6; j++)
            fout << (rand() % 10 + 1) << " ";
        fout << "\n";
    }
}

// ------------------ Skaitymas iš failo ------------------
template <typename Container>
Container skaitytiIsFailo(const string& failo_pav) {
    Container c;
    ifstream f(failo_pav);
    if (!f) return c;

    string header; getline(f, header);

    while (!f.eof()) {
        Studentas s;
        if (f >> s) c.push_back(std::move(s));
    }

    return c;
}

// Eksplisitiniai šablonų instanciavimai
template vector<Studentas> skaitytiIsFailo<vector<Studentas>>(const string&);
template list<Studentas> skaitytiIsFailo<list<Studentas>>(const string&);

// ------------------ Rezultatų rodymas ------------------
void rodytiRezultatus(vector<Studentas>& studentai) {
    cout << left << setw(15) << "Vardas" << setw(20) << "Pavarde"
        << setw(12) << "GalutinisVid" << setw(12) << "GalutinisMed" << endl;
    for (auto& s : studentai) {
        cout << left << setw(15) << s.vardas() << setw(20) << s.pavarde()
            << setw(12) << fixed << setprecision(2) << s.galutinisVid()
            << setw(12) << s.galutinisMed() << endl;
    }
}

// ------------------ Skirstymo strategijos su erase ------------------

// ================= 1️ Pirma strategija =================
// Pirma strategija: naudojamas papildomas konteineris blogi studentai + erase iteratoriumi
template <typename Container>
void skirstytiStrategija1(Container& studentai, const string&, double& split_time, double& write_time) {
    auto start_split = high_resolution_clock::now();
    Container blogi;
    auto it = studentai.begin();
    while (it != studentai.end()) {
        if (it->galutinisVid() < 5) {
            blogi.insert(blogi.end(), *it);
            it = studentai.erase(it);
        }
        else {
            ++it;
        }
    }
    split_time = duration<double>(high_resolution_clock::now() - start_split).count();

    auto start_write = high_resolution_clock::now();
    ofstream out_g("geri.txt"), out_b("blogi.txt");
    for (auto& s : studentai) out_g << s.vardas() << " " << s.pavarde() << " " << s.galutinisVid() << "\n";
    for (auto& s : blogi) out_b << s.vardas() << " " << s.pavarde() << " " << s.galutinisVid() << "\n";
    write_time = duration<double>(high_resolution_clock::now() - start_write).count();
}

// ================= 2️ Antroji strategija =================
// Antroji strategija: tiesiog kviečiama pirmoji, todėl naudoja tą patį erase principą
template <typename Container>
void skirstytiStrategija2(Container& studentai, const string& s, double& split_time, double& write_time) {
    skirstytiStrategija1(studentai, s, split_time, write_time);
}

// ================= 3️ Trečioji strategija =================
// Trečioji strategija: taip pat tiesiog kviečiama pirmoji, erase principas vienodas
template <typename Container>
void skirstytiStrategija3(Container& studentai, const string& s, double& split_time, double& write_time) {
    skirstytiStrategija1(studentai, s, split_time, write_time);
}

// Eksplisitiniai šablonų instanciavimai
template void skirstytiStrategija1<vector<Studentas>>(vector<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija1<list<Studentas>>(list<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija2<vector<Studentas>>(vector<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija2<list<Studentas>>(list<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija3<vector<Studentas>>(vector<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija3<list<Studentas>>(list<Studentas>&, const string&, double&, double&);

// ------------------ Rezultatų rašymas į README ------------------
void irasytiRezultatusReadme(double v_read, double v_split, double v_write,
    double l_read, double l_split, double l_write,
    const string& failo_pav) {
    ofstream fout("readme.md", ios::app);
    fout << "\nRezultatai failui: " << failo_pav << "\n";
    fout << left << setw(15) << "Konteineris"
        << setw(15) << "Nuskaitymas(s)"
        << setw(15) << "Skirstymas(s)"
        << setw(15) << "Rasymas(s)" << "\n";
    fout << string(60, '-') << "\n";
    fout << left << setw(15) << "Vector" << setw(15) << v_read << setw(15) << v_split << setw(15) << v_write << "\n";
    fout << left << setw(15) << "List" << setw(15) << l_read << setw(15) << l_split << setw(15) << l_write << "\n";
    fout.close();
}
