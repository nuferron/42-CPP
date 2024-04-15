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
    this->_type = a.getType();
    std::cout << "Animal: Copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal: Destructor called" << std::endl;
}

Animal  &Animal::operator=(const Animal &a)
{
    this->_type = a.getType();
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->_type);
}

void    Animal::makeSound(void) const
{
    std::cout << "Random animal sound" << std::endl;
}
