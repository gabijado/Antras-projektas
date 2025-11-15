#pragma once
#include "Studentas.h"
#include <vector>
#include <list>
#include <string>

// Funkciju prototipai
void generuotiFaila(int kiekis);
void rodytiRezultatus(std::vector<Studentas>& studentai);

// Skaitymas is failo
template <typename Container>
Container skaitytiIsFailo(const std::string& failo_pav);

// Skirstymo strategija 1 (naudojant papildoma konteineri)
template <typename Container>
void skirstytiStrategija1(Container& studentai, const std::string& konteinerio_pav,
    double& skirstymo_laikas, double& rasymo_laikas);

// Skirstymo strategija 2 (naudojant erase)
template <typename Container>
void skirstytiStrategija2(Container& studentai, const std::string& konteinerio_pav,
    double& skirstymo_laikas, double& rasymo_laikas);

// Skirstymo strategija 3 (naudojant partition)
template <typename Container>
void skirstytiStrategija3(Container& studentai, const std::string& konteinerio_pav,
    double& skirstymo_laikas, double& rasymo_laikas);

// Rezultatu irasymas i README faila
void irasytiRezultatusReadme(double v_read, double v_split, double v_write,
    double l_read, double l_split, double l_write,
    const std::string& failo_pav);
