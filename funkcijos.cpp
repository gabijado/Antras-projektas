#include "funkcijos.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void generuotiFaila(int kiekis) {
    string failo_pav = "studentai_" + to_string(kiekis) + ".txt";
    ofstream fout(failo_pav);
    fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde";
    for (int i = 1; i <= 5; i++) fout << setw(8) << ("ND" + to_string(i));
    fout << setw(8) << "Egz" << endl;

    for (int i = 0; i < kiekis; i++) {
        fout << left << setw(15) << ("Vardas" + to_string(i + 1))
            << setw(15) << ("Pavarde" + to_string(i + 1));
        for (int j = 0; j < 5; j++) fout << setw(8) << (rand() % 10 + 1);
        fout << setw(8) << (rand() % 10 + 1) << endl;
    }
    fout.close();
    cout << "Sugeneruotas failas: " << failo_pav << endl;
}

template <typename Container>
Container skaitytiIsFailo(const string& failo_pav) {
    Container studentai;
    ifstream fin(failo_pav);
    if (!fin) { cout << "Nepavyko atidaryti failo\n"; return studentai; }
    string header; getline(fin, header);
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        istringstream ss(line);
        Studentas s;
        s.readStudent(ss);
        studentai.push_back(s);
    }
    return studentai;
}

// template instantiation
template vector<Studentas> skaitytiIsFailo<vector<Studentas>>(const string&);
template list<Studentas> skaitytiIsFailo<list<Studentas>>(const string&);

void rodytiRezultatus(vector<Studentas>& studentai) {
    cout << left << setw(15) << "Vardas" << setw(20) << "Pavarde"
        << setw(12) << "GalutinisVid" << setw(12) << "GalutinisMed" << endl;
    for (auto& s : studentai) {
        cout << left << setw(15) << s.vardas() << setw(20) << s.pavarde()
            << setw(12) << fixed << setprecision(2) << s.galutinisVid()
            << setw(12) << s.galutinisMed() << endl;
    }
}

// Skirstymo strategijos (paprastai skirsto pagal galutinisVid() < 5)
template <typename Container>
void skirstytiStrategija1(const Container& studentai, const string& konteinerio_pav,
    double& skirstymo_laikas, double& rasymo_laikas) {
    // paprasta kopija ir skirstymas
}

template <typename Container>
void skirstytiStrategija2(Container& studentai, const string& konteinerio_pav,
    double& skirstymo_laikas, double& rasymo_laikas) {
    // optimizuota su erase
}

template <typename Container>
void skirstytiStrategija3(Container& studentai, const string& konteinerio_pav,
    double& skirstymo_laikas, double& rasymo_laikas) {
    // optimizuota su partition
}

// template instantiation
template void skirstytiStrategija1<vector<Studentas>>(const vector<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija1<list<Studentas>>(const list<Studentas>&, const string&, double&, double&);

template void skirstytiStrategija2<vector<Studentas>>(vector<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija2<list<Studentas>>(list<Studentas>&, const string&, double&, double&);

template void skirstytiStrategija3<vector<Studentas>>(vector<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija3<list<Studentas>>(list<Studentas>&, const string&, double&, double&);

void irasytiRezultatusReadme(double v_read, double v_split, double v_write,
    double l_read, double l_split, double l_write,
    const string& failo_pav) {
    ofstream fout("readme.md", ios::app);
    fout << "\n## Rezultatai (" << failo_pav << ")\n";
    fout.close();
}
