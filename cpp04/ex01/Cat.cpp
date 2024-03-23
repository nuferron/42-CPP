#include "Cat.hpp"

Cat::Cat(): Animal::Animal("Cat"), _type("Cat")
{
    this->_brain = new Brain();
    std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(const Cat &c): Animal("Cat")
{
    this->_brain = c.getBrain();
    std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
    (void)c;
    return (*this);
}

std::string Cat::getType(void) const
{
    return(_type);
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow mrruh" << std::endl;
}