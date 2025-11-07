#include "Studentas.h"
#include <sstream>   // <- ČIA būtina
#include <algorithm>
#include <numeric>
using namespace std;

Studentas::Studentas(string v, string p, vector<int> nd, int egz)
    : vardas_(v), pavarde_(p), nd_(nd), egz_(egz) {
    skaiciuotiGalutinius();
}

void Studentas::skaiciuotiGalutinius() {
    if (nd_.empty()) {
        galutinisVid_ = 0.6 * egz_;
        galutinisMed_ = 0.6 * egz_;
        return;
    }
    double vid = accumulate(nd_.begin(), nd_.end(), 0.0) / nd_.size();
    vector<int> copy_nd = nd_;
    sort(copy_nd.begin(), copy_nd.end());
    double med = copy_nd[copy_nd.size() / 2];
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
    skaiciuotiGalutinius();
    return is;
}
