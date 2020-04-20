//
// Created by Lukasz on 14.03.2020.
//

#ifndef KAMIL_SAMOCHODY_H
#define KAMIL_SAMOCHODY_H

#include <string>
#include <ostream>

class Samochody {

private:
    std::string marka;
    std::string model;
    unsigned int rocznik;
    double pojemnosc;
    unsigned int przebieg;
    std::string typSkrzyniBiegow;

public:
    explicit Samochody(std::string Marka = "Brak", std::string Model = "Brak", unsigned int Rocznik = 0, double Pojemnosc = 0,
            unsigned int Przebieg = 0, std::string TypSkrzyniBiegow = "Manual" );
    friend std::ostream & operator<< (std::ostream &out, const Samochody &s);
     std::string ZwrocModel() const;
     double ZwrocPojemnosc() const;
    std::string ZwrocMarke() const;
    unsigned int ZwrocRocznik() const;
    unsigned int ZwrocPrzebieg() const;
    std::string ZwrocTypSkrzyniBiegow() const;


};


#endif //KAMIL_SAMOCHODY_H
