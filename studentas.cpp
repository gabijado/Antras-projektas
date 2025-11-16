#include "Studentas.h"
#include <iomanip>
#include <algorithm>
#include <numeric>

// --- Konstruktoriai ---
Studentas::Studentas()
    : Zmogus(), egz_(0), galutinisVid_(0.0), galutinisMed_(0.0), nd_(std::vector<int>()) {
}

Studentas::Studentas(const std::string& v, const std::string& p, const std::vector<int>& nd, int egz)
    : Zmogus(v, p), nd_(nd), egz_(egz) {
    skaiciuotiGalutinius();
}

// --- Kopijavimo konstruktorius ---
Studentas::Studentas(const Studentas& other)
    : Zmogus(other.vardas_, other.pavarde_), nd_(other.nd_), egz_(other.egz_),
    galutinisVid_(other.galutinisVid_), galutinisMed_(other.galutinisMed_) {
}

// --- Kopijavimo priskyrimo operatorius ---
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
        nd_ = other.nd_;
        egz_ = other.egz_;
        galutinisVid_ = other.galutinisVid_;
        galutinisMed_ = other.galutinisMed_;
    }
    return *this;
}

// --- Destruktorius ---
Studentas::~Studentas() {
    nd_.clear();           // Išvalome namų darbų vektorių
    egz_ = 0;              // Nustatome egzaminą į 0
    galutinisVid_ = 0.0;   // Nustatome galutinį vidurkį į 0
    galutinisMed_ = 0.0;   // Nustatome galutinę medianą į 0
    vardas_.clear();       // Išvalome vardą
    pavarde_.clear();      // Išvalome pavardę
}

// --- Įvesties operatorius ---
std::istream& operator>>(std::istream& is, Studentas& s) {
    s.nd_.clear();
    is >> s.vardas_ >> s.pavarde_;
    int x;
    for (int i = 0; i < 5; i++) { // Įvedame 5 namų darbų rezultatus
        is >> x;
        s.nd_.push_back(x);
    }
    is >> s.egz_;
    s.skaiciuotiGalutinius();
    return is;
}

// --- Išvesties operatorius ---
std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << std::left << std::setw(15) << s.vardas_
        << std::setw(20) << s.pavarde_
        << std::setw(12) << std::fixed << std::setprecision(2) << s.galutinisVid_
        << std::setw(12) << std::fixed << std::setprecision(2) << s.galutinisMed_;
    return os;
}

// --- Abstraktaus metodo implementacija ---
void Studentas::skaiciuotiGalutinius() {
    if (nd_.empty()) {
        galutinisVid_ = galutinisMed_ = 0.6 * egz_;
        return;
    }

    // Vidurkis
    double vid = std::accumulate(nd_.begin(), nd_.end(), 0.0) / nd_.size();

    // Mediana
    std::vector<int> sorted_nd = nd_;
    std::sort(sorted_nd.begin(), sorted_nd.end());

    double med;
    size_t size = sorted_nd.size();
    if (size % 2 == 0)
        med = (sorted_nd[size / 2 - 1] + sorted_nd[size / 2]) / 2.0;
    else
        med = sorted_nd[size / 2];

    galutinisVid_ = 0.4 * vid + 0.6 * egz_;
    galutinisMed_ = 0.4 * med + 0.6 * egz_;
}
