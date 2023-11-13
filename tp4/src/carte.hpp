#ifndef __CARTE_HPP__
#define __CARTE_HPP__

class UsineCarte;

class Carte
{
    friend UsineCarte;

private:
    int valeur;
public:
    unsigned_int getValeur() const { return valeur; };
};

#endif