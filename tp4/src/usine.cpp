#include "usine.hpp"

UsineCarte::UsineCarte(/* args */)
{
}

UsineCarte::~UsineCarte()
{
}

std::unique_ptr<Carte> getCarte()
{
    return std::make_unique<Carte> (Carte());
}
