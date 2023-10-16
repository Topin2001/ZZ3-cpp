#include <point.hpp>

Point::Point(/* args */)
{
}

Point::~Point()
{
}

std::ostream &operator<<(std::ostream &flux, Point const & p)
{
    p.afficher(flux);
    return flux;
}
