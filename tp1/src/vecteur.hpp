#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <ostream>
#include <exception>

class Vecteur
{
protected:


public:
    int *list_chiante;
    int taille;
    Vecteur(/* args */);
    Vecteur(Vecteur const &);
    ~Vecteur();
    Vecteur &operator=(Vecteur const &);
    void push(int);
    int &operator[](int);

    friend std::ostream &operator<<(std::ostream &, Vecteur const &);
    friend Vecteur operator+(Vecteur const &, Vecteur const &);
    friend Vecteur operator*(Vecteur const &, Vecteur const &);

    class Iterateur
    {
    private:
        int *ptr;

    public:
        Iterateur(int *p) : ptr(p){};
        ~Iterateur() {};

        Iterateur operator++();
        Iterateur operator++(int);
        int operator*();
        bool operator==(const Iterateur &);
        bool operator!=(const Iterateur &);
    };

    Iterateur begin() { return Iterateur(list_chiante); };
    Iterateur end() { return Iterateur(list_chiante + taille); };
};

Vecteur operator+(Vecteur const &, Vecteur const &);
std::ostream &operator<<(std::ostream &, Vecteur const &);
Vecteur operator*(Vecteur const &, Vecteur const &);

#endif