#include "Studentas.h"
#include "funkcijos.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Pagrindinė programos funkcija
int main() {
    srand(time(0));
    int veiksmas;
    do {
        cout << "\n===== MENIU =====\n";
        cout << "1 - Ivesti studentus ranka\n";
        cout << "2 - Generuoti atsitiktinius duomenis\n";
        cout << "3 - Nuskaityti duomenis is failo\n";
        cout << "4 - Sugeneruoti testinius failus (1k,10k,100k,1M,10M)\n";
        cout << "5 - Palyginti vector ir list veikimo greiti (su strategijos pasirinkimu)\n";
        cout << "6 - Iseiti\n";
        cout << "Pasirinkite: "; cin >> veiksmas; cin.ignore();

        if (veiksmas == 1) {
            vector<Studentas> studentai;
            int n; cout << "Kiek studentu ivesti? "; cin >> n; cin.ignore();
            for (int i = 0; i < n; i++) {
                string vard, pav; cout << "Vardas: "; getline(cin, vard);
                cout << "Pavarde: "; getline(cin, pav);
                vector<int> nd; int ndkiek; cout << "Kiek ND? "; cin >> ndkiek; cin.ignore();
                for (int j = 0; j < ndkiek; j++) { int p; cout << "ND" << j + 1 << ": "; cin >> p; cin.ignore(); nd.push_back(p); }
                int egz; cout << "Egzaminas: "; cin >> egz; cin.ignore();
                studentai.push_back(Studentas(vard, pav, nd, egz));
            }
            rodytiRezultatus(studentai);
        }
        else if (veiksmas == 2) {
            vector<Studentas> studentai;
            int n; cout << "Kiek sugeneruoti? "; cin >> n; cin.ignore();
            for (int i = 0; i < n; i++) {
                vector<int> nd; for (int j = 0; j < 5; j++) nd.push_back(rand() % 10 + 1);
                int egz = rand() % 10 + 1;
                studentai.push_back(Studentas("Vardas" + to_string(i + 1), "Pavarde" + to_string(i + 1), nd, egz));
            }
            rodytiRezultatus(studentai);
        }
        else if (veiksmas == 3) {
            string failo_pav; cout << "Iveskite failo pavadinima: "; getline(cin, failo_pav);
            auto studentai = skaitytiIsFailo<vector<Studentas>>(failo_pav);
            rodytiRezultatus(studentai);
        }
        else if (veiksmas == 4) {
            vector<int> dydziai = { 1000,10000,100000,1000000,10000000 };
            for (int k : dydziai) generuotiFaila(k);
        }
        else if (veiksmas == 5) {
            string failo_pav; cout << "Iveskite failo pavadinima: "; getline(cin, failo_pav);
            int strategija; cout << "Pasirinkite strategija (1,2,3): "; cin >> strategija; cin.ignore();

            vector<double> v_read_times, v_split_times, v_write_times;
            vector<double> l_read_times, l_split_times, l_write_times;

            // Vykdyti tris kartus ir imti vidurki
            for (int kartas = 1; kartas <= 3; kartas++) {
                auto start_v = high_resolution_clock::now();
                auto studentai_v = skaitytiIsFailo<vector<Studentas>>(failo_pav);
                auto end_v = high_resolution_clock::now();
                double v_read = duration<double>(end_v - start_v).count();

                // Skirstymas ir rasymas vector konteineriu
                double v_split = 0.0, v_write = 0.0;
                if (strategija == 1) skirstytiStrategija1<vector<Studentas>>(studentai_v, "vector", v_split, v_write);
                else if (strategija == 2) skirstytiStrategija2<vector<Studentas>>(studentai_v, "vector", v_split, v_write);
                else skirstytiStrategija3<vector<Studentas>>(studentai_v, "vector", v_split, v_write);

                // Skirstymas ir rasymas vector konteineriu
                auto start_l = high_resolution_clock::now();
                auto studentai_l = skaitytiIsFailo<list<Studentas>>(failo_pav);
                auto end_l = high_resolution_clock::now();
                double l_read = duration<double>(end_l - start_l).count();

                // Skirstymas ir rasymas list konteineriu
                double l_split = 0.0, l_write = 0.0;
                if (strategija == 1) skirstytiStrategija1<list<Studentas>>(studentai_l, "list", l_split, l_write);
                else if (strategija == 2) skirstytiStrategija2<list<Studentas>>(studentai_l, "list", l_split, l_write);
                else skirstytiStrategija3<list<Studentas>>(studentai_l, "list", l_split, l_write);

                // Kaupimas rezultatų
                v_read_times.push_back(v_read); v_split_times.push_back(v_split); v_write_times.push_back(v_write);
                l_read_times.push_back(l_read); l_split_times.push_back(l_split); l_write_times.push_back(l_write);
            }

            // Apskaičiuoti vidurkius
            auto avg = [](const vector<double>& v) { return accumulate(v.begin(), v.end(), 0.0) / v.size(); };

            double v_read_avg = avg(v_read_times);
            double v_split_avg = avg(v_split_times);
            double v_write_avg = avg(v_write_times);
            double l_read_avg = avg(l_read_times);
            double l_split_avg = avg(l_split_times);
            double l_write_avg = avg(l_write_times);

            // Spausdinti rezultatus
            cout << "\n================ VEIKIMO LAIKAI ================\n";
            cout << left << setw(12) << "Konteineris" << setw(15) << "Nuskaitymas" << setw(15) << "Skirstymas" << setw(15) << "Rasymas\n";
            cout << "-----------------------------------------------\n";
            cout << left << setw(12) << "Vector" << setw(15) << v_read_avg << setw(15) << v_split_avg << setw(15) << v_write_avg << "\n";
            cout << left << setw(12) << "List" << setw(15) << l_read_avg << setw(15) << l_split_avg << setw(15) << l_write_avg << "\n";

            irasytiRezultatusReadme(v_read_avg, v_split_avg, v_write_avg, l_read_avg, l_split_avg, l_write_avg, failo_pav);
        }

    } while (veiksmas != 6);

    cout << "Programa baige darba.\n";
    return 0;
}
