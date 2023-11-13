#ifndef __RESSOURCE_HPP__
#define __RESSOURCE_HPP__

class Ressource
{
private:
    unsigned stock;
public:
    Ressource(int stock = 0) : stock(stock) {};
    unsigned getStock() const { return stock; };
    void setStock(unsigned stock) { this->stock = stock; };
    void consommer(unsigned consommation) { stock -= consommation; };
};


#endif