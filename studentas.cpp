#include "studentas.h"
#include <algorithm>
#include <sstream>
#include <iomanip>


double mediana(std::vector<int> paz) {
    if (paz.empty()) return 0.0;
    std::sort(paz.begin(), paz.end());
    int n = static_cast<int>(paz.size());
    if (n % 2 == 0)
        return (paz[n / 2 - 1] + paz[n / 2]) / 2.0;
    else
        return paz[n / 2];
}


static double vidurkis(const std::vector<int>& paz) {
    if (paz.empty()) return 0.0;
    double sum = 0;
    for (int p : paz) sum += p;
    return sum / paz.size();
}

// readStudent: skaito iš istream formatu: vardas pavarde nd1 nd2 ... ndN egz
std::istream& Studentas::readStudent(std::istream& is) {
    // Mes skaitome vardą ir pavardę. Toliau - penki (ar kiti) ND + egz.
    // Kad būtų lanksčiau, perskaitome iki galo eilutės ir parse'int.
    std::string line;
    if (!std::getline(is, line)) return is; // jei nėra duomenų
    if (line.empty()) return is;

    std::istringstream ss(line);
    ss >> vardas_ >> pavarde_;

    paz_.clear();
    int pazymys;
    // Skaitysime visus pažymius, išskyrus paskutinį (kuris bus egzaminas)
        // Čia nuskaitome visus skaičius į vektorių, tada paskutinį laikysime egzaminu.
    std::vector<int> temp;
    while (ss >> pazymys) {
        temp.push_back(pazymys);
    }

    if (!temp.empty()) {
        // Paskutinis elementas - egzaminas
        egz_ = temp.back();
        temp.pop_back();
    } else {
        egz_ = 0;
    }
    paz_ = std::move(temp);
    return is;
}

// Apskaičiuoja galutinį balą: (agregator(paz) * 0.4) + (egz_ * 0.6)
double Studentas::galutinisVid(double (*agregator)(const std::vector<int>&)) const {
    double agg = 0.0;
    if (agregator) agg = agregator(paz_);
    else agg = vidurkis(paz_);
    return agg * 0.4 + static_cast<double>(egz_) * 0.6;
}

double Studentas::galutinisMed() const {
    double m = mediana(paz_);
    return m * 0.4 + static_cast<double>(egz_) * 0.6;
}


bool compare(const Studentas& a, const Studentas& b) {
    if (a.pavarde() == b.pavarde())
        return a.vardas() < b.vardas();
    return a.pavarde() < b.pavarde();
}

bool comparePagalPavarde(const Studentas& a, const Studentas& b) {
    return a.pavarde() < b.pavarde();
}

bool comparePagalEgz(const Studentas& a, const Studentas& b) {
    return a.egzaminas() < b.egzaminas();
}
