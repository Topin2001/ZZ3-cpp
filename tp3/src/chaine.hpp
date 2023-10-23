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
std::string chaine(const Args &...x)
{
    std::stringstream ss;
    ((ss << chaine(x) << " "), ...);
    return ss.str();
};

template <class... Args, size_t... Is>
std::string chaine_helper(const std::tuple<Args...> &x, const std::integer_sequence<size_t, Is...>&)
{
    return chaine(std::get<Is>(x)...);
};

template <class... Args>
std::string chaine(const std::tuple<Args...> &x)
{
    std::stringstream ss;
    ss << chaine_helper(x, std::make_integer_sequence<size_t, sizeof...(Args)>());
    return ss.str();
};


#endif