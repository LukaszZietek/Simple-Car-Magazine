//
// Created by Lukasz on 14.03.2020.
//

#include "Samochody.h"


Samochody::Samochody(std::string Marka, std::string Model, unsigned int Rocznik, double Pojemnosc,
unsigned int Przebieg, std::string TypSkrzyniBiegow)
{
    marka = Marka;
    model = Model;
    rocznik = Rocznik;
    pojemnosc = Pojemnosc;
    przebieg = Przebieg;
    typSkrzyniBiegow = TypSkrzyniBiegow;


}


std::string Samochody::ZwrocModel() const {
    return model;
}

double Samochody::ZwrocPojemnosc() const
{
    return pojemnosc;
}

std::string Samochody::ZwrocMarke() const
{
    return marka;
}

unsigned int Samochody::ZwrocRocznik() const
{
    return rocznik;
}

unsigned int Samochody::ZwrocPrzebieg () const
{
    return przebieg;
}

std::string Samochody::ZwrocTypSkrzyniBiegow() const
{
    return typSkrzyniBiegow;
}


std::ostream & operator<< (std::ostream &out, const Samochody &s)
{
    out << s.marka;
    out << " ";
    out << s.model;
    out << " ";
    out << s.rocznik;
    out << " ";
    out << s.pojemnosc;
    out << " ";
    out << s.przebieg;
    out << " ";
    out << s.typSkrzyniBiegow;
    out << std::endl;
    return out;


}
