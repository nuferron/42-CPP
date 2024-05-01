#ifndef EASYFIND_H
# define EASYFIND_H

#include <iostream>

template <typename T> bool  easyfind(T &var, int num)
{
    typename T::const_iterator ptr = var.begin();

    while (ptr != var.end())
    {
        if (*ptr == num)
            return (1);
        ptr++;
    }
    return (0);
}

#endif