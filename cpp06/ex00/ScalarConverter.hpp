#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cctype>

class   ScalarConverter
{
    public:
        static void convert(const std::string &str);
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &s);
        ScalarConverter &operator=(const ScalarConverter &s);
        static std::string putChar(const std::string &str);
        static int whichNumericType(const std::string &str);
};

#endif