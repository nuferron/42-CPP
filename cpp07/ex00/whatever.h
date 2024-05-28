#ifndef WHATEVER_H
# define WHATEVER_H

#include <iostream>

template <typename T> void swap(T &a, T &b)
{
    T c = a;

	//std::cout << "my swap" << std::endl;
    a = b;
    b = c;
}

template <typename T> T min(T f, T s)
{
	//std::cout << "my min" << std::endl;
    if (f < s)
        return (f);
    return (s);
}

template <typename T> T max(T f, T s)
{
	//std::cout << "my max" << std::endl;
    if (f > s)
        return (f);
    return (s);
}

#endif
