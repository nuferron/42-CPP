#ifndef EASYFIND_H
# define EASYFIND_H

#include <iostream>

template <typename T> bool  easyfind(T &var, int num)
{
    typename T::const_iterator it = var.begin();
    typename T::const_iterator ite = var.end();

    while (it != ite)
    {
        if (*it == num)
            return (1);
        it++;
    }
    return (0);
}

#endif