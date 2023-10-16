#include <cartesien.hpp>
#include <polaire.hpp>
#include <math.h>

Cartesien::Cartesien(double x, double y)
{
    this->x = x;
    this->y = y;
}

Cartesien::Cartesien():Cartesien(0, 0)
{
}

Cartesien::Cartesien(Polaire const & p) {
    p.convertir(*this);
}

Cartesien::~Cartesien()
{
}

void Cartesien::afficher(std::ostream &flux) const
{
    flux << "(x=" << x << ";y=" << y << ")";
}

void Cartesien::convertir(Polaire & p) const {

    double a = std::atan2(y, x) * 180 / M_PI;
    double d = std::hypot(x, y);

    p.setAngle(a);
    p.setDistance(d);
}

void Cartesien::convertir(Cartesien & c) const {

    double x = this->getX();
    double y = this->getY();

    c.setX(x);
    c.setY(y);
}