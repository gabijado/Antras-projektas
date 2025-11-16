#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogu.h"
#include <vector>
#include <iostream>

class Studentas : public Zmogus {
private:
    std::vector<int> nd_;
    int egz_;
    double galutinisVid_;
    double galutinisMed_;

public:
    // Konstruktoriai
    Studentas();
    Studentas(const std::string& v, const std::string& p, const std::vector<int>& nd, int egz);

    // Rule of Three
    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);
    ~Studentas(); // Destruktorius

    // Get'eriai
    double galutinisVid() const { return galutinisVid_; }
    double galutinisMed() const { return galutinisMed_; }

    // Implementuojame virtualią funkciją iš bazinės klasės
    void skaiciuotiGalutinius() override;

    // Įvesties/išvesties operatoriai
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
    friend std::istream& operator>>(std::istream& is, Studentas& s);
};

#endif // STUDENTAS_H
