#ifndef WHATEVER_H
# define WHATEVER_H

#include <iostream>

template <typename T> void swap(T &a, T &b)
{
    T c = a;

    a = b;
    b = c;
}

template <typename T> T min(T f, T s)
{
    if (f < s)
        return (f);
    return (s);
}

template <typename T> T max(T f, T s)
{
    if (f > s)
        return (f);
    return (s);
}

#endif