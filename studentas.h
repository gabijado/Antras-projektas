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
    int egz_;
    double galutinisVid_;
    double galutinisMed_;

public:
    // --- Konstruktoriai ---
    Studentas();
    Studentas(const std::string& v, const std::string& p, const std::vector<int>& nd, int egz);

    // --- Rule of Three metodai ---
    Studentas(const Studentas& other);            // Kopijavimo konstruktorius
    Studentas& operator=(const Studentas& other); // Kopijavimo priskyrimo operatorius
    ~Studentas();                                 // Destruktorius

    // --- Get'eriai ---
    std::string vardas() const { return vardas_; }
    std::string pavarde() const { return pavarde_; }
    double galutinisVid() const { return galutinisVid_; }
    double galutinisMed() const { return galutinisMed_; }

    // --- Pagalbinės funkcijos ---
    void skaiciuotiGalutinius();
    std::istream& readStudent(std::istream& is);

    // --- Įvesties/išvesties operatoriai ---
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
    friend std::istream& operator>>(std::istream& is, Studentas& s);
};

#endif
