#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal::WrongAnimal("WrongCat"), _type("WrongCat")
{
    std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &c): WrongAnimal("WrongCat")
{
    (void)c;
    std::cout << "WrongCat: Copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat: Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &c)
{
    (void)c;
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << "Meow mrruh" << std::endl;
}