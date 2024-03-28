#include "Animal.hpp"

Animal::Animal()
{
    _type = "Beast";
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const std::string str)
{
    _type = str;
    std::cout << "Animal: String constructor called" << std::endl;
}

Animal::Animal(const Animal &a)
{
    this->_type = a._type;
    std::cout << "Animal: Copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal: Destructor called" << std::endl;
}

Animal  &Animal::operator=(const Animal &a)
{
    this->_type = a._type;
    return (*this);
}