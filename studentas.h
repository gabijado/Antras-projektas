#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include "funkcijos.h"

using namespace std;

class Studentas {
private:
    string vardas_;
    string pavarde_;
    vector<int> nd_;
    int egz_;
    double gal_vid_;
    double gal_med_;

public:
    Studentas() : egz_(0), gal_vid_(0.0), gal_med_(0.0) {}      
    Studentas(istream& is);                                  

    // get'eriai
    inline string vardas() const { return vardas_; }
    inline string pavarde() const { return pavarde_; }
    inline double galVid() const { return gal_vid_; }
    inline double galMed() const { return gal_med_; }


    istream& readStudent(istream&);

    // skaičiavimo metodai
    double skaiciuotiVidurki() const;
    double skaiciuotiMediana() const;

    // galutinio balo skaičiavimas
    void skaiciuotiGalutinius();

    friend bool compare(const Studentas&, const Studentas&);
    friend bool comparePagalPavarde(const Studentas&, const Studentas&);
    friend bool comparePagalEgza(const Studentas&, const Studentas&);
};

#endif
