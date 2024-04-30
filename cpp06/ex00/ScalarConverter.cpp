#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &s) {(void)s;}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &s)
{
    (void)s;
    return (*this);
}

void    ScalarConverter::special(double n)
{
    std::cout << "char: impossible" << std::endl
                << "int: impossible" << std::endl;
    if (!n)
    {
        std::cout << "float: nanf" << std::endl
                    << "double: nan" << std::endl;
    }
    else
    {
        std::cout << "float: " << n << "f" << std::endl
                    << "double: " << n << std::endl;
    }
}

int    ScalarConverter::isDigit(const char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

void    ScalarConverter::printChar(const std::string &str)
{
    char    c;
    int     n;

    if (str[0] == '\'')
        c = str[1];
    else
        c = str[0];
    n = static_cast<int>(c);
    std::cout << "char: '" << c << "'" << std::endl
                << "int: " << n << std::endl
                << "float: " << n << ".0f" << std::endl
                << "double: " << n << ".0" << std::endl;
}

void    ScalarConverter::printNumber(double n)
{
    if (n < INT_MIN || n > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(n) << std::endl;
    /////// FLOAT ////////
    if (n < -FLT_MAX || n > FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else
    {
        std::cout << "float: " << static_cast<float>(n);
        if (n == (int)n)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
    /////// DOUBLE /////////
    std::cout << "double: " << n;
    if (n == (int)n)
        std::cout << ".0";
    std::cout << std::endl;
}

void    ScalarConverter::convert(const std::string &str)
{
    if ((str[0] == '\'' && str[1] && str[2] == '\'' && !str[3]) || (!isDigit(str[0]) && !str[1]))
    {
        printChar(str);
        return ;
    }
    double n = atof(str.c_str());
    if (n != n || n - n != n - n // n != n will only be true if n = nan // n - n != n - n will only be true if n = +-inf
        || (!n && (str[0] != '0' || (str[1] && str[1] != '0'))))
    {
        special(n);
        return ;
    }
    if (n < 0 || n > 127)
        std::cout << "char: impossible" << std::endl;
    else if (n < 32 || n > 126)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
    printNumber(n);
}