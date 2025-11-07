#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <vector>
#include <list>
#include <string>

// Mediana
double mediana(std::vector<int> paz);

// Skaityti is failo 
template <typename Container>
Container skaitytiIsFailo(const std::string& failo_pav);

// Rodyti rezultatus
void rodytiRezultatus(std::vector<Studentas>& studentai);

// Skirstyti ir rasyti i failus
template <typename Container>
void skirstytiIrRasyti(const Container& studentai, const std::string& konteinerio_pav,
    double& skirstymo_laikas, double& rasymo_laikas);

// Naujos strategijos 
template <typename Container>
void skirstytiStrategija1(const Container& studentai, const std::string& konteinerio_pav,
    double& skirstymo_laikas, double& rasymo_laikas);

template <typename Container>
void skirstytiStrategija2(Container& studentai, const std::string& konteinerio_pav,
    double& skirstymo_laikas, double& rasymo_laikas);

template <typename Container>
void skirstytiStrategija3(Container& studentai, const std::string& konteinerio_pav,
    double& skirstymo_laikas, double& rasymo_laikas);

// Generuoti testini faila
void generuotiFaila(int kiekis);

// Irasyti rezultatus i readme
void irasytiRezultatusReadme(double v_read, double v_split, double v_write,
    double l_read, double l_split, double l_write,
    const std::string& failo_pav);

#endif
