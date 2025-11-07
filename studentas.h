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
    Studentas(std::string v, std::string p, std::vector<int> nd, int egz);

    
    Studentas(const Studentas& other);
    Studentas(Studentas&& other) noexcept;
    Studentas& operator=(const Studentas& other);
    Studentas& operator=(Studentas&& other) noexcept;

    // --- Destruktorius ---
    ~Studentas();  // Aprašytas Studentas.cpp faile

    // --- Get'ai ---
    std::string vardas() const { return vardas_; }
    std::string pavarde() const { return pavarde_; }
    double galutinisVid() const { return galutinisVid_; }
    double galutinisMed() const { return galutinisMed_; }

    // --- Pagalbinės funkcijos ---
    void skaiciuotiGalutinius();
    std::istream& readStudent(std::istream& is);
};

#endif
