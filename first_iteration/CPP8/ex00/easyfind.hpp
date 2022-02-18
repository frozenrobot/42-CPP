#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <map>
#include <iostream>
#include <exception>

template < typename T >
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it;
    typename T::iterator ite = container.end();
    for (it = container.begin(); it != ite; it++)
    {
        if (*it == value)
            return (it);
    }
    throw std::exception();
}

#endif