#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> nd_;
    int egz_;
    double gal_vid_;
    double gal_med_;

public:
    Studentas() : vardas_(""), pavarde_(""), egz_(0), gal_vid_(0.0), gal_med_(0.0) {}
    Studentas(const std::string& vardas, const std::string& pavarde,
        const std::vector<int>& nd, int egz)
        : vardas_(vardas), pavarde_(pavarde), nd_(nd), egz_(egz) {
        skaiciuotiGalutinius();
    }

    // get'eriai
    std::string vardas() const { return vardas_; }
    std::string pavarde() const { return pavarde_; }
    double galutinisVid() const { return gal_vid_; }
    double galutinisMed() const { return gal_med_; }
    int egzaminas() const { return egz_; }

    std::istream& readStudent(std::istream& is);

    double skaiciuotiVidurki() const;
    double skaiciuotiMediana() const;
    void skaiciuotiGalutinius();
};

#endif
