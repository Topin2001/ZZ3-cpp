#ifndef POINT_HPP
#define POINT_HPP

#include <ostream>

class Polaire;

class Cartesien;

class Point
{
protected:
public:
    Point();
    ~Point();
    virtual void afficher(std::ostream &) const = 0;
    virtual void convertir(Polaire &) const = 0;
    virtual void convertir(Cartesien &) const = 0;
};

std::ostream &operator<<(std::ostream &, Point const &);

#endif