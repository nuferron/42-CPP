#include "Dog.hpp"

Dog::Dog(): Animal::Animal("Dog"), _type("Dog")
{
    std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(const Dog &d): Animal::Animal("Dog")
{
    (void)d;
    std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &d)
{
    (void)d;
    return (*this);
}

std::string Dog::getType(void) const
{
    return(_type);
}

void    Dog::makeSound(void) const
{
    std::cout << "Woof arf" << std::endl;
}