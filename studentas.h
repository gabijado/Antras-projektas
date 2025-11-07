#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <istream>

double mediana(std::vector<int> paz); // deklaracija jei norite naudoti iš kitur

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> paz_;   // namų darbų pažymiai
    int egz_{0};

public:
    Studentas() = default;
    // Konstruktorius, kuris nuskaito studento duomenis iš stream 
    explicit Studentas(std::istream& is) { readStudent(is); }

    // Getter'iai (inline)
    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    inline const std::vector<int>& pazymiai() const { return paz_; }
    inline int egzaminas() const { return egz_; }

    // Apskaičiuoja galutinį balą pagal duotą agregavimo funkciją (pvz. mediana ar vidurkis)
    double galutinisVid(double (*agregator)(const std::vector<int>&) = nullptr) const;
    double galutinisMed() const;

    // Nuskaito vieno studento duomenis iš stream 
    std::istream& readStudent(std::istream& is);

    void pridetiPazymys(int p) { paz_.push_back(p); }
};

bool compare(const Studentas& a, const Studentas& b);                // pagal vardą+pavardę
bool comparePagalPavarde(const Studentas& a, const Studentas& b);    // pagal pavardę
bool comparePagalEgz(const Studentas& a, const Studentas& b);        // pagal egzaminą

#endif // STUDENTAS_H
