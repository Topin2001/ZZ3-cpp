#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <cartesien.hpp>
#include <polaire.hpp>

#include <vector>

template <typename T>
class Nuage
{
private:
    std::vector<T> points;

public:
    using const_iterator = std::vector<T>::const_iterator;

    Nuage() {}
    Nuage(const std::vector<T> &points) : points(points) {}
    ~Nuage() {}

    void ajouter(const T &p) { points.push_back(p); }

    size_t size() const { return points.size(); }

    const_iterator begin() const { return points.begin(); }
    const_iterator end() const { return points.end(); }
};



#endif