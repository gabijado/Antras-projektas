#include "Studentas.h"
#include <iomanip>
#include <sstream>

// --- Konstruktoriai ---
Studentas::Studentas()
    : vardas_(""), pavarde_(""), egz_(0), galutinisVid_(0.0), galutinisMed_(0.0) {
}

Studentas::Studentas(const std::string& v, const std::string& p, const std::vector<int>& nd, int egz)
    : vardas_(v), pavarde_(p), nd_(nd), egz_(egz) {
    skaiciuotiGalutinius();
}

// --- Kopijavimo konstruktorius ---
Studentas::Studentas(const Studentas& other)
    : vardas_(other.vardas_), pavarde_(other.pavarde_),
    nd_(other.nd_), egz_(other.egz_),
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
    vardas_.clear();
    pavarde_.clear();
    nd_.clear();
    egz_ = 0;
    galutinisVid_ = 0.0;
    galutinisMed_ = 0.0;
}

// --- Įvesties operatorius ---
std::istream& operator>>(std::istream& is, Studentas& s) {
    s.nd_.clear();
    is >> s.vardas_ >> s.pavarde_;

    int pazymys;
    while (is >> pazymys) s.nd_.push_back(pazymys);

    if (!s.nd_.empty()) {
        s.egz_ = s.nd_.back();
        s.nd_.pop_back();
    }
    else {
        s.egz_ = 0;
    }

    s.skaiciuotiGalutinius();

    return is;
}

// --- Išvesties operatorius ---
std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << std::left << std::setw(15) << s.vardas_ << std::setw(20) << s.pavarde_
        << std::setw(12) << std::fixed << std::setprecision(2) << s.galutinisVid_
        << std::setw(12) << std::fixed << std::setprecision(2) << s.galutinisMed_;
    return os;
}

// --- Pagalbinės funkcijos ---
void Studentas::skaiciuotiGalutinius() {
    if (nd_.empty()) {
        galutinisVid_ = galutinisMed_ = 0.6 * egz_;
        return;
    }

    double vid = std::accumulate(nd_.begin(), nd_.end(), 0.0) / nd_.size();

    std::vector<int> copy_nd = nd_; // kopijuojame, nes sort modifikuoja
    std::sort(copy_nd.begin(), copy_nd.end());

    double med;
    size_t size = copy_nd.size();
    if (size % 2 == 0)
        med = (copy_nd[size / 2 - 1] + copy_nd[size / 2]) / 2.0;
    else
        med = copy_nd[size / 2];

    galutinisVid_ = 0.4 * vid + 0.6 * egz_;
    galutinisMed_ = 0.4 * med + 0.6 * egz_;
}

std::istream& Studentas::readStudent(std::istream& is) {
    return is >> *this;
}
