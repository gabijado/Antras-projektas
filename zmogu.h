#pragma once
#include <string>

class Zmogus {
protected:
    std::string vardas_;
    std::string pavarde_;

public:
    Zmogus() : vardas_(""), pavarde_("") {}
    Zmogus(const std::string& v, const std::string& p) : vardas_(v), pavarde_(p) {}

    virtual ~Zmogus() {}

    // Getteriai
    std::string vardas() const { return vardas_; }
    std::string pavarde() const { return pavarde_; }

    // Grynas virtualus metodas — privalomas įgyvendinimas derived klasėse
    virtual void skaiciuotiGalutinius() = 0;
};

