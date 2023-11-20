#ifndef __CONSOMMATEUR_HPP__
#define __CONSOMMATEUR_HPP__

#include <vector>
#include <iostream>
#include <memory>
#include "ressource.hpp"

using ressources_t = std::vector<std::weak_ptr<Ressource>>;

class Consommateur
{
    friend ressources_t;

private:
    unsigned besoin = 0;
    std::shared_ptr<Ressource> ressource = nullptr;

public:
    Consommateur(unsigned besoin, std::shared_ptr<Ressource> ressource) : besoin(besoin), ressource(ressource){};

    void puiser()
    {
        if (ressource != nullptr)
        {
            if (besoin > ressource->getStock())
            {
                besoin -= ressource->getStock();
                ressource->setStock(0);
                ressource = nullptr;
            }
            else
            {
                ressource->consommer(besoin);
            }
        };
    };
};

std::ostream &operator<<(std::ostream &os, const ressources_t &ressources)
{
    for (auto &ressource : ressources)
    {
        if (ressource.expired())
        {
            os << "- ";
        }
        else
        {
            os << ressource.lock()->getStock() << " ";
        }
    }
    return os;
};

#endif