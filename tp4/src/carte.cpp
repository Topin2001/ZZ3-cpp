#include "carte.hpp"
#include "usine.hpp"

void remplir(paquet_t &paquet, UsineCarte &usine)
{
    while (std::unique_ptr<Carte> carte = usine.getCarte())
    {
        paquet.push_back(std::move(carte));
    }
}

std::ostream &operator<<(std::ostream &os, paquet_t const &paquet_t)
{
    for (auto const &carte : paquet_t)
    {
        os << carte->getValeur() << " ";
    }
    return os;
}

Carte::Carte(Carte &&c) : valeur(c.valeur)
{
    nbr_carte++;
}