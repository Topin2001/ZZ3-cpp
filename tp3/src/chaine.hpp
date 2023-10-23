#ifndef CHAINE_HPP
#define CHAINE_HPP

#include <iostream>
#include <exception>
#include <string>
#include <sstream>

class ExceptionChaine : public std::exception
{
private:
    std::string message;

public:
    ExceptionChaine(std::string const &type) { this->message = "Conversion en chaine impossible pour '" + type + "'"; };
    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

template <typename T>
std::string chaine(const T &x)
{
    std::string str = demangle(typeid(x).name());
    throw ExceptionChaine(str);
}

std::string chaine(const std::string &x)
{
    return x;
};

std::string chaine(const int &x)
{
    return std::to_string(x);
};

std::string chaine(const double &x)
{
    return std::to_string(x);
};

template <class... Args>
std::string chaine(const Args & ... x)
{
    std::stringstream ss;
    ((ss << chaine(x) << " "), ...);
    return ss.str();
};

#endif