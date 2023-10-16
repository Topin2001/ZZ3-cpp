#include <iostream>
#include <vecteur.hpp>

int main() {
    Vecteur vec1;
    vec1 = Vecteur(); // Utilisation de l'opérateur de copie

    std::cout << vec1.list_chiante << std::endl;
    
    Vecteur vec2;
    vec2[0] = 1;
    vec2[1] = 2;
    
    // Vecteur vec3 = vec1 + vec2; // Utilisation de l'opérateur de concaténation
    // std::cout << vec3 << std::endl;
    
    // std::cout << "Produit scalaire : " << vec2 * vec3 << std::endl;
    
    // // Utilisation d'un itérateur pour parcourir le vecteur
    // for (Vecteur::Iterateur it = vec2.begin(); it != vec2.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
    
    return 0;
}
