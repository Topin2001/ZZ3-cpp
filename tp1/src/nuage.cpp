#include <nuage.hpp>
#include <cartesien.hpp>
#include <polaire.hpp>

Nuage::Nuage(/* args */)
{
}

Nuage::~Nuage()
{
}

void Nuage::ajouter(Point &p)
{
    std::vector<Point *>::push_back(&p);
}

Cartesien barycentre(Nuage const &n)
{
    double x = 0;
    double y = 0;
    for (auto const &p : n)
    {
        Cartesien c;
        p->convertir(c);
        x += c.getX();
        y += c.getY();
    }

    return Cartesien(x / n.size(), y / n.size());
}

BarycentreCartesien::BarycentreCartesien(/* args */)
{
}

BarycentreCartesien::~BarycentreCartesien()
{
}

Cartesien BarycentreCartesien::operator()(Nuage const &n)
{
    return barycentre(n);
}

BarycentrePolaire::BarycentrePolaire(/* args */)
{
}

BarycentrePolaire::~BarycentrePolaire()
{
}

Polaire BarycentrePolaire::operator()(Nuage const &n)
{
    Polaire p(barycentre(n));
    return p;
}