#include "Studentas.h"
#include <sstream>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

Studentas::Studentas() = default;

Studentas::Studentas(string v, string p, vector<int> nd, int egz)
    : vardas_(std::move(v)), pavarde_(std::move(p)), nd_(std::move(nd)), egz_(egz) {
    skaiciuotiGalutinius();
}

Studentas::Studentas(const Studentas& other)
    : vardas_(other.vardas_), pavarde_(other.pavarde_),
    nd_(other.nd_), egz_(other.egz_),
    galutinisVid_(other.galutinisVid_), galutinisMed_(other.galutinisMed_) {
}

Studentas::Studentas(Studentas&& other) noexcept
    : vardas_(std::move(other.vardas_)), pavarde_(std::move(other.pavarde_)),
    nd_(std::move(other.nd_)), egz_(other.egz_),
    galutinisVid_(other.galutinisVid_), galutinisMed_(other.galutinisMed_) {
    other.egz_ = 0;
    other.galutinisVid_ = other.galutinisMed_ = 0.0;
}

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

Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this != &other) {
        vardas_ = std::move(other.vardas_);
        pavarde_ = std::move(other.pavarde_);
        nd_ = std::move(other.nd_);
        egz_ = other.egz_;
        galutinisVid_ = other.galutinisVid_;
        galutinisMed_ = other.galutinisMed_;
        other.egz_ = 0;
        other.galutinisVid_ = other.galutinisMed_ = 0.0;
    }
    return *this;
}

// --- Destruktorius ---
Studentas::~Studentas() {
    
}

void Studentas::skaiciuotiGalutinius() {
    if (nd_.empty()) {
        galutinisVid_ = galutinisMed_ = 0.6 * egz_;
        return;
    }

    double vid = accumulate(nd_.begin(), nd_.end(), 0.0) / nd_.size();
    vector<int> copy_nd = nd_;
    sort(copy_nd.begin(), copy_nd.end());

    double med;
    size_t size = copy_nd.size();
    if (size % 2 == 0)
        med = (copy_nd[size / 2 - 1] + copy_nd[size / 2]) / 2.0;
    else
        med = copy_nd[size / 2];

    galutinisVid_ = 0.4 * vid + 0.6 * egz_;
    galutinisMed_ = 0.4 * med + 0.6 * egz_;
}

istream& Studentas::readStudent(istream& is) {
    is >> vardas_ >> pavarde_;
    nd_.clear();
    int paz;
    while (is >> paz) {
        nd_.push_back(paz);
    }
    if (!nd_.empty()) {
        egz_ = nd_.back();
        nd_.pop_back();
    }
    else {
        egz_ = 0;
    }

    skaiciuotiGalutinius();
    return is;
}
