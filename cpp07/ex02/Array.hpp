#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>

class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &a);
        ~Array();
        Array   &operator=(const Array &a);
        T   &operator[](unsigned int id) const;
        unsigned int    size(void) const;
        class   OutOfBounds: public std::exception {
            const char *what(void) {
                return ("Array index out of bounds");
            }
        };
        class   NullArray: public std::exception {
            const char *what(void) {
                return ("Array is not initialized");
            }
        };
    private:
        unsigned int    _total;
        T               *_array;
};

#include "Array.tpp"

#endif