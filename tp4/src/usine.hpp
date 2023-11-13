#ifndef __USINE_HPP__
#define __USINE_HPP__

#include "carte.hpp"


class UsineCarte
{
private:
    unsigned NombreCarte;
    unsigned Compteur = 0;
    UsineCarte(UsineCarte const &) = delete;
    UsineCarte(UsineCarte &&) = delete;
public:
    std::unique_ptr<Carte> getCarte();
    UsineCarte(unsigned NombreCarte = 52) : NombreCarte(NombreCarte) {};
};



#endif