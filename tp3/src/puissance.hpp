template <int N>
class Puissance
{
public:
    static double valeur(double x)
    {
        return x * Puissance<N - 1>::valeur(x);
    } 
};

template<>
class Puissance<0>
{
public:
    static double valeur(double x)
    {
        return 1.0;
    }
};


