#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> nd_;
    int egz_ = 0;
    double galutinisVid_ = 0.0;
    double galutinisMed_ = 0.0;

public:
    // --- Konstruktoriai ---
    Studentas();
    Studentas(const std::string& v, const std::string& p, const std::vector<int>& nd, int egz);

    // --- Kopijavimo ir perkėlimo konstruktoriai bei priskyrimo operatoriai ---
    Studentas(const Studentas& other);
    Studentas(Studentas&& other);
    Studentas& operator=(const Studentas& other);
    Studentas& operator=(Studentas&& other);

    // --- Destruktorius ---
    ~Studentas();

    // --- Get'eriai ---
    std::string vardas() const { return vardas_; }
    std::string pavarde() const { return pavarde_; }
    double galutinisVid() const { return galutinisVid_; }
    double galutinisMed() const { return galutinisMed_; }

    // --- Pagalbinės funkcijos ---
    void skaiciuotiGalutinius();
    std::istream& readStudent(std::istream& is);
};

#endif

