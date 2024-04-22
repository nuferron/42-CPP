#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &s) {(void)s;}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &s)
{
    (void)s;
    return (*this);
}

int ScalarConverter::whichNumericType(const std::string &str)
{
    bool    dot = false;
    int     len = str.length();
    int     i = -1;

    if (len == 1 && isalpha(str[0]))
        return (0); //Char
    while (++i < len)
    {
        if (!dot && str[i] == '.')
            dot = true;
        else if (str[i] < '0' && str[i] > '9')
            break ;
    }
    if (i == len && !dot)
        return (1); //Int
    if (i == len && dot)
        return (3); //Double
    if (i == len - 1 && str[i] == 'f')
        return (2); //Float
    return (-1); //None of the above
}

std::string ScalarConverter::putChar(const std::string &str)
{
    int len = str.length();
    int ascii;

    if (len == 1 && isalpha(str[0]))
        return ("\'" + str + "\'");
    try
    {
        ascii = std::stoi(str);
    }
    catch (std::exception &ex)
    {
        return (std::string("impossible"));
    }
    if (ascii < ' ' || ascii == 127)
        return (std::string("Non displayable"));
    return (std::string(1, static_cast<char>(ascii)));
}

void    ScalarConverter::convert(const std::string &s)
{
    double type = whichNumericType(s);
    const char    *str = &s[0];

    std::cout << "Char: " << putChar(s) << std::endl;
    switch (static_cast<int>(type))
    {
        case 0:
        {
            std::cout << "Int: " << static_cast<int>(s[0]) << std::endl;
            std::cout << "Float: " << static_cast<float>(s[0]) << std::endl;
            std::cout << "Double: " << static_cast<double>(s[0]) << std::endl;
            break ;
        }
        case 1:
        {
            type = std::atoi(str);
            std::cout << "Int: " << type << std::endl;
            std::cout << "Float: " << static_cast<float>(type)<< std::endl;
            std::cout << "Double: " << static_cast<double>(type) << std::endl;
            break ;
        }
        case 2:
        {
            type = std::atof(str);
            std::cout << "Int: " << static_cast<int>(type) << std::endl;
            std::cout << "Float: " << type;
            if (type == (int)type)
                std::cout << "0";
            std::cout << "f" << std::endl;
            std::cout << "Double: " << static_cast<double>(type) << std::endl;
            break ;
        }
        case 3:
        {
            type = std::atof(str);
            std::cout << "Int: " << static_cast<int>(type) << std::endl;
            std::cout << "Float: " << static_cast<float>(type) << "f" << std::endl;
            std::cout << "Double: " << type << std::endl;
            break ;
        }
        default:
            std::cout << "Not sure what this is: " << s << std::endl;
            break ;
    }
}