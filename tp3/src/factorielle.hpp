#include <iostream>

template <int N>
class Factorielle
{
public:
    static unsigned long int const valeur = N * Factorielle<N - 1>::valeur;
};

template <>
class Factorielle<0>
{
public:
    static unsigned long int const valeur = 1;
};