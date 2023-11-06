#include <factorielle.hpp>
#include <puissance.hpp>

template <int N>
class Exponentielle
{
public:
    static double valeur(double x)
    {
        return (Puissance<N>::valeur(x)) / Factorielle<N>::valeur + Puissance<N - 1>::valeur(x);
    }
};

template <>
class Exponentielle<0>
{
public:
    static double valeur(double x)
    {
        return x;
    }
};
