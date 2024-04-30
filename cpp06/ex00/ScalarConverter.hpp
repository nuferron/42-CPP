#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cfloat>
#include <climits>

class   ScalarConverter
{
    public:
        static void convert(const std::string &str);
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &s);
        ScalarConverter &operator=(const ScalarConverter &s);
        static void     printChar(const std::string &str);
        static void     printNumber(double n);
        static void     special(double n);
        static int      isDigit(const char c);
};

#endif