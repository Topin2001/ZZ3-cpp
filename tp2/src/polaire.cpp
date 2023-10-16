#include <polaire.hpp>
#include <cartesien.hpp>
#include <sstream>
#include <math.h>

Polaire::Polaire(double a, double d)
{
    this->a = a;
    this->d = d;
}

Polaire::Polaire() : Polaire(0, 0)
{
}

Polaire::Polaire(Cartesien const & c) {
    c.convertir(*this);
}

Polaire::~Polaire()
{
}

void Polaire::afficher(std::ostream &flux) const
{
    flux << "(a=" << a << ";d=" << d << ")";
}

void Polaire::convertir(Cartesien & c) const {

    double x = d * std::cos(a * M_PI / 180);
    double y = d * std::sin(a * M_PI / 180);

    c.setX(x);
    c.setY(y);
}

void Polaire::convertir(Polaire & p) const {

    double a = this->getAngle();
    double d = this->getDistance();

    p.setAngle(a);
    p.setDistance(d);
}
