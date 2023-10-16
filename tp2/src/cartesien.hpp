#ifndef CARTESIEN_HPP
#define CARTESIEN_HPP

#include <ostream>
#include <point.hpp>

class Cartesien : public Point
{
private:
    double x;
    double y;
public:
    Cartesien(double, double);
    Cartesien();
    Cartesien(Polaire const &);
    ~Cartesien();

    double getX() const { return x; };
    double getY() const { return y; };

    void setX(double x) { this->x = x; };
    void setY(double y) { this->y = y; };

    void afficher(std::ostream &) const;

    void convertir(Polaire &) const override;
    void convertir(Cartesien &) const override; 
};


#endif