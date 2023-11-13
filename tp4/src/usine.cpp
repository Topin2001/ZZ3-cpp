#include "usine.hpp"

std::unique_ptr<Carte> UsineCarte::getCarte()
{
    if (Compteur >= NombreCarte)
    {
        return nullptr;
    }
    else
    {
        return std::make_unique<Carte>(Carte(Compteur++));
    }
}
