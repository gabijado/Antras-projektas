#pragma once
#include <iostream>
#include <vector>
#include <string>
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
    Studentas() = default;
    Studentas(std::string v, std::string p, std::vector<int> nd, int egz);

    std::string vardas() const { return vardas_; }
    std::string pavarde() const { return pavarde_; }
    double galutinisVid() const { return galutinisVid_; }
    double galutinisMed() const { return galutinisMed_; }

    void skaiciuotiGalutinius();
    std::istream& readStudent(std::istream& is);
};
