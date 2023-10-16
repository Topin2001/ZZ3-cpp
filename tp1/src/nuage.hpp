#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <point.hpp>
#include <vector>

class Nuage : public std::vector<Point *>
{
private:
public:
    Nuage(/* args */);
    ~Nuage();

    void ajouter(Point &);
};

Cartesien barycentre(Nuage const &);

class BarycentreCartesien
{
private:
    /* data */
public:
    BarycentreCartesien(/* args */);
    ~BarycentreCartesien();
    Cartesien operator()(Nuage const &);
};

class BarycentrePolaire
{
private:
    /* data */
public:
    BarycentrePolaire(/* args */);
    ~BarycentrePolaire();
    Polaire operator()(Nuage const &);
};

#endif