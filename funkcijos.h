#pragma once
#include "Studentas.h"
#include <vector>
#include <list>
#include <string>

void generuotiFaila(int kiekis);
void rodytiRezultatus(std::vector<Studentas>& studentai);

template <typename Container>
Container skaitytiIsFailo(const std::string& failo_pav);

template <typename Container>
void skirstytiStrategija1(Container& studentai, const std::string& konteinerio_pav,
    double& skirstymo_laikas, double& rasymo_laikas);

template <typename Container>
void skirstytiStrategija2(Container& studentai, const std::string& konteinerio_pav,
    double& skirstymo_laikas, double& rasymo_laikas);

template <typename Container>
void skirstytiStrategija3(Container& studentai, const std::string& konteinerio_pav,
    double& skirstymo_laikas, double& rasymo_laikas);

void irasytiRezultatusReadme(double v_read, double v_split, double v_write,
    double l_read, double l_split, double l_write,
    const std::string& failo_pav);
