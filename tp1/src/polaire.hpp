#ifndef POLAIRE_HPP
#define POLAIRE_HPP

#include <ostream>
#include <point.hpp>

class Polaire : public Point
{
private:
    double a;
    double d;

public:
    Polaire(double, double);
    Polaire();
    Polaire(Cartesien const &);
    ~Polaire();
    double getAngle() const { return a; };
    double getDistance() const { return d; };
    void setAngle(double a) { this->a = a; };
    void setDistance(double d) { this->d = d; };
    void afficher(std::ostream &) const override;

    void convertir(Cartesien &) const override;
    void convertir(Polaire &) const override;
};

#endif