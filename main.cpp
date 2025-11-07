#include "Studentas.h"
#include "funkcijos.h"
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <string>

using namespace std;

int main() {
    srand(time(0));

    int veiksmas;
    cout << "Pasirinkite veiksma:\n";
    cout << "1 - Ivesti studentus ranka\n";
    cout << "2 - Generuoti atsitiktinius duomenis\n";
    cout << "3 - Nuskaityti duomenis is failo\n";
    cout << "4 - Sugeneruoti testinius failus (1k,10k,100k,1M,10M)\n";
    cout << "5 - Palyginti vector ir list veikimo greiti (su strategijos pasirinkimu)\n";
    cout << "6 - Iseiti\n";
    cin >> veiksmas;

    if (veiksmas == 1) {
        vector<Studentas> studentai;
        int n;
        cout << "\nKiek studentu norite ivesti? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "\n--- Studentas " << i + 1 << " ---\n";
            string vardas, pavarde;
            cout << "Iveskite varda: ";
            cin >> vardas;
            cout << "Iveskite pavarde: ";
            cin >> pavarde;

            int nd_kiek;
            cout << "Kiek namu darbu pazymiu: ";
            cin >> nd_kiek;

            vector<int> nd;
            for (int j = 0; j < nd_kiek; j++) {
                int p;
                cout << "Iveskite " << j + 1 << " pazymi: ";
                cin >> p;
                nd.push_back(p);
            }

            int egz;
            cout << "Iveskite egzamino pazymi: ";
            cin >> egz;

            Studentas s(vardas, pavarde, nd, egz);
            studentai.push_back(s);
        }

        cout << "\nRezultatai:\n";
        rodytiRezultatus(studentai);
    }

    else if (veiksmas == 2) {
        int kiek;
        cout << "Kiek studentu generuoti? ";
        cin >> kiek;

        vector<Studentas> studentai;
        for (int i = 0; i < kiek; i++) {
            string vard = "Vardas" + to_string(i + 1);
            string pav = "Pavarde" + to_string(i + 1);
            vector<int> nd;
            int nd_kiek = rand() % 5 + 3; // 3–7 pazymiai
            for (int j = 0; j < nd_kiek; j++)
                nd.push_back(rand() % 10 + 1);
            int egz = rand() % 10 + 1;

            Studentas s(vard, pav, nd, egz);
            studentai.push_back(s);
        }

        cout << "Sugeneruota " << kiek << " atsitiktiniu studentu.\n";
        rodytiRezultatus(studentai);
    }

    else if (veiksmas == 3) {
        string failo_pav;
        cout << "Iveskite failo pavadinima (pvz. studentai.txt): ";
        cin >> failo_pav;

        cout << "\nNuskaitomi duomenys is failo...\n";
        try {
            vector<Studentas> studentai = skaitytiIsFailo<vector<Studentas>>(failo_pav);
            if (studentai.empty())
                cout << "Failas tuscias arba netinkamas formatas.\n";
            else {
                cout << "\nNuskaityta " << studentai.size() << " studentu.\n";
                rodytiRezultatus(studentai);
            }
        }
        catch (exception& e) {
            cerr << "Klaida skaitant faila: " << e.what() << endl;
        }
    }

    else if (veiksmas == 4) {
        cout << "Generuojami testiniai failai: 1k, 10k, 100k, 1M, 10M studentu...\n";
        vector<int> kiekiai = { 1000, 10000, 100000, 1000000, 10000000 };
        for (int k : kiekiai) generuotiFaila(k);
        cout << "Failai sekmingai sugeneruoti.\n";
    }

    else if (veiksmas == 5) {
        cout << "Palyginimas tarp vector ir list veikimo:\n";
        cout << "Pasirinkite strategija (1, 2 arba 3): ";
        int strategija;
        cin >> strategija;

        string failo_pav;
        cout << "Iveskite failo pavadinima su studentais (pvz. studentai.txt): ";
        cin >> failo_pav;

        double v_read = 0, v_split = 0, v_write = 0;
        double l_read = 0, l_split = 0, l_write = 0;

        cout << "\nAnalizuojamas VECTOR konteineris...\n";
        vector<Studentas> studentai_v = skaitytiIsFailo<vector<Studentas>>(failo_pav);

        if (strategija == 1)
            skirstytiStrategija1(studentai_v, "vector", v_split, v_write);
        else if (strategija == 2)
            skirstytiStrategija2(studentai_v, "vector", v_split, v_write);
        else
            skirstytiStrategija3(studentai_v, "vector", v_split, v_write);

        cout << "\nAnalizuojamas LIST konteineris...\n";
        list<Studentas> studentai_l = skaitytiIsFailo<list<Studentas>>(failo_pav);

        if (strategija == 1)
            skirstytiStrategija1(studentai_l, "list", l_split, l_write);
        else if (strategija == 2)
            skirstytiStrategija2(studentai_l, "list", l_split, l_write);
        else
            skirstytiStrategija3(studentai_l, "list", l_split, l_write);

        irasytiRezultatusReadme(v_read, v_split, v_write, l_read, l_split, l_write, "rezultatai.txt");
        cout << "\nRezultatai issaugoti faile 'rezultatai.txt'.\n";
    }

    else if (veiksmas == 6) {
        cout << "Programa baige darba.\n";
        return 0;
    }

    else {
        cout << "Neteisingas pasirinkimas.\n";
    }

    return 0;
}
