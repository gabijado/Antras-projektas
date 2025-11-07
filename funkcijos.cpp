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

// Skirstymo strategija 1
template <typename Container>
void skirstytiStrategija1(Container& studentai, const string&, double& split_time, double& write_time) {
    auto start_split = high_resolution_clock::now();
    Container geri, blogi;
    for (auto& s : studentai) {
        if (s.galutinisVid() >= 5) geri.push_back(s);
        else blogi.push_back(s);
    }
    auto end_split = high_resolution_clock::now();
    split_time = duration<double>(end_split - start_split).count();

    auto start_write = high_resolution_clock::now();
    ofstream out_g("geri.txt"), out_b("blogi.txt");
    for (auto& s : geri) out_g << s.vardas() << " " << s.pavarde() << " " << s.galutinisVid() << "\n";
    for (auto& s : blogi) out_b << s.vardas() << " " << s.pavarde() << " " << s.galutinisVid() << "\n";
    out_g.close(); out_b.close();
    auto end_write = high_resolution_clock::now();
    write_time = duration<double>(end_write - start_write).count();
}

// Skirstymo strategija 2 (naudojant erase)
template <typename Container>
void skirstytiStrategija2(Container& studentai, const string&, double& split_time, double& write_time) {
    auto start_split = high_resolution_clock::now();
    Container blogi;
    auto it = studentai.begin();
    while (it != studentai.end()) {
        if (it->galutinisVid() < 5) {
            blogi.push_back(*it);
            it = studentai.erase(it);
        }
        else it++;
    }
    auto end_split = high_resolution_clock::now();
    split_time = duration<double>(end_split - start_split).count();

    auto start_write = high_resolution_clock::now();
    ofstream out_g("geri.txt"), out_b("blogi.txt");
    for (auto& s : studentai) out_g << s.vardas() << " " << s.pavarde() << " " << s.galutinisVid() << "\n";
    for (auto& s : blogi) out_b << s.vardas() << " " << s.pavarde() << " " << s.galutinisVid() << "\n";
    write_time = duration<double>(high_resolution_clock::now() - start_write).count();
}

// Skirstymo strategija 3 (partition)
template <typename Container>
void skirstytiStrategija3(Container& studentai, const string&, double& split_time, double& write_time) {
    auto start_split = high_resolution_clock::now();
    Container blogi;
    auto p = partition(studentai.begin(), studentai.end(), [](const Studentas& s) { return s.galutinisVid() >= 5; });
    blogi.insert(blogi.end(), p, studentai.end());
    studentai.erase(p, studentai.end());
    auto end_split = high_resolution_clock::now();
    split_time = duration<double>(end_split - start_split).count();

    auto start_write = high_resolution_clock::now();
    ofstream out_g("geri.txt"), out_b("blogi.txt");
    for (auto& s : studentai) out_g << s.vardas() << " " << s.pavarde() << " " << s.galutinisVid() << "\n";
    for (auto& s : blogi) out_b << s.vardas() << " " << s.pavarde() << " " << s.galutinisVid() << "\n";
    write_time = duration<double>(high_resolution_clock::now() - start_write).count();
}

template void skirstytiStrategija1<vector<Studentas>>(vector<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija1<list<Studentas>>(list<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija2<vector<Studentas>>(vector<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija2<list<Studentas>>(list<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija3<vector<Studentas>>(vector<Studentas>&, const string&, double&, double&);
template void skirstytiStrategija3<list<Studentas>>(list<Studentas>&, const string&, double&, double&);

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
