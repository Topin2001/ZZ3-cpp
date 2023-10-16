#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <cartesien.hpp>
#include <polaire.hpp>

#include <iostream>
#include <vector>

template <typename T>
class Nuage
{
private:
    std::vector<T> points;

public:
    using const_iterator = typename std::vector<T>::const_iterator;

    Nuage() {}
    Nuage(const std::vector<T> &points) : points(points) {}
    ~Nuage() {}

    void ajouter(const T &p) { points.push_back(p); }

    size_t size() const { return points.size(); }

    const_iterator begin() const { return points.begin(); }
    const_iterator end() const { return points.end(); }
};

template <typename T>
T barycentre_v1(const Nuage<T> &n)
{
    Cartesien p(0, 0);
    double x_sum = 0.0;
    double y_sum = 0.0;

    if (n.size() == 0)
    {
        return p;
    }

    for (T const & pt : n)
    {
        Cartesien c = pt;
        x_sum += c.getX();
        y_sum += c.getY();
    }
    p.setX(x_sum / n.size());
    p.setY(y_sum / n.size());

    return p;
}

#endif