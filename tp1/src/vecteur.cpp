#include <vecteur.hpp>

Vecteur::Vecteur(/* args */)
{
    taille = 0;
    list_chiante = nullptr;
}

Vecteur::Vecteur(Vecteur const &vec)
{
    taille = 0;
    list_chiante = nullptr;
    *this = vec;
}

Vecteur::~Vecteur()
{
    delete[] list_chiante;
}

void Vecteur::push(int i)
{
    taille += 1;
    
}

Vecteur &Vecteur::operator=(Vecteur const &vec)
{
    if (this != &vec)
    {
        delete[] list_chiante;
        taille = vec.taille;
        list_chiante = new int[taille];
        for (int i = 0; i < taille; i++)
        {
            list_chiante[i] = vec.list_chiante[i];
        }
    }
    return *this;
}

int &Vecteur::operator[](int index)
{
    if (index < 0 || index >= taille)
    {
        throw std::out_of_range("Index is out of range");
    }
    return list_chiante[index];
}

std::ostream &operator<<(std::ostream &s, Vecteur const &vec)
{
    for (int i = 0; i < vec.taille; i++)
    {
        s << vec.list_chiante[i] << ", ";
    }
    return s;
}

Vecteur operator+(Vecteur const &vec1, Vecteur const &vec2)
{
    Vecteur vec3;
    vec3.taille = vec1.taille + vec2.taille;
    vec3.list_chiante = new int[vec3.taille];

    for (int i = 0; i < vec1.taille; i++)
    {
        vec3.list_chiante[i] = vec1.list_chiante[i];
    }

    for (int j = 0; j < vec2.taille; j++)
    {
        vec3.list_chiante[vec1.taille + j] = vec2.list_chiante[j];
    }

    return vec3;
}

Vecteur operator*(Vecteur const &vec1, Vecteur const &vec2)
{
    if (vec1.taille != vec2.taille)
    {
        throw std::invalid_argument("Vect doesn't have the same size");
    }
    Vecteur vec3;
    vec3.taille = vec1.taille;
    vec3.list_chiante = new int[vec3.taille];

    for (int i = 0; i < vec3.taille; i++)
    {
        vec3.list_chiante[i] = vec1.list_chiante[i] * vec2.list_chiante[i];
    }

    return vec3;
}

Vecteur::Iterateur Vecteur::Iterateur::operator++()
{
    ++ptr;
    return *this;
}

Vecteur::Iterateur Vecteur::Iterateur::operator++(int)
{
    Iterateur temp = *this;
    ++ptr;
    return temp;
}

int Vecteur::Iterateur::operator*()
{
    return *ptr;
}

bool Vecteur::Iterateur::operator==(const Iterateur &it)
{
    return ptr == it.ptr;
}

bool Vecteur::Iterateur::operator!=(const Iterateur &it)
{
    return ptr != it.ptr;
}