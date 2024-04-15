#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    _type = "Beast";
    std::cout << "Animal: Default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string str)
{
    _type = str;
    std::cout << "Animal: String constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &a)
{
    this->_type = a._type;
    std::cout << "Animal: Copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal: Destructor called" << std::endl;
}

AAnimal  &AAnimal::operator=(const AAnimal &a)
{
    this->_type = a._type;
    return (*this);
}
