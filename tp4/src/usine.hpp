#ifndef __USINE_HPP__
#define __USINE_HPP__

#include <memory>
#include "carte.hpp"


class UsineCarte
{
private:
    /* data */
public:
    UsineCarte(/* args */);
    ~UsineCarte();
    std::unique_ptr<Carte> getCarte();
};



#endif