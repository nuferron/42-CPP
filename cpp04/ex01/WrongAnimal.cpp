#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    _type = "Beast";
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string str)
{
    _type = str;
    std::cout << "WrongAnimal: String constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
    this->_type = a.getType();
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: Destructor called" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &a)
{
    this->_type = a.getType();
    return (*this);
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "Random WrongAnimal sound" << std::endl;
}