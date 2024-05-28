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

        class   OutOfBoundsException;
        class   NullArrayException;

    private:
        unsigned int    _total;
        T               *_array;
};

template <typename T>
class   Array<T>::OutOfBoundsException: public std::exception
{
	public:
    	const char *what(void) const throw ();
};

template <typename T>
class   Array<T>::NullArrayException: public std::exception
{
	public:
    	const char *what(void) const throw ();
};

#include "Array.tpp"

#endif
