#ifndef __CARTE_HPP__
#define __CARTE_HPP__

#include <memory>
#include <iostream>
#include <vector>

class UsineCarte;

class Carte
{
    friend UsineCarte;

private:
    unsigned valeur;
    inline unsigned static nbr_carte = 0;
    Carte(unsigned valeur) : valeur(valeur) { nbr_carte++; };
    Carte(Carte const &) = delete;

public:
    unsigned getValeur() const { return valeur; };
    Carte(Carte &&);
    ~Carte() { nbr_carte--; };
    unsigned static getCompteur() { return nbr_carte; };
};

using paquet_t = std::vector<std::unique_ptr<Carte>>;

void remplir(paquet_t &paquet, UsineCarte &usine);

std::ostream &operator<<(std::ostream &os, paquet_t const &paquet);

#endif