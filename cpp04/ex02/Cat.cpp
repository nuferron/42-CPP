#include "Cat.hpp"

Cat::Cat(): Animal::Animal("Cat"), _type("Cat")
{
    this->_brain = new Brain();
    std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(Cat &c): Animal::Animal("Cat")
{
    this->_brain = new Brain();
    this->_brain = c._brain;
    std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat: Destructor called" << std::endl;
}

Cat &Cat::operator=(Cat &c)
{
    if (this->_brain)
        delete _brain;
    this->_brain = c._brain;
    return (*this);
}

std::string Cat::getType(void) const
{
    return(this->_type);
}

void    Cat::setIdea(const std::string &str) const
{
    this->_brain->setIdea(str);
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow mrruh" << std::endl;
}

void    Cat::printIdeas(void) const
{
    int id = this->_brain->getId();
    for (int i = 0; i < id; i++)
        std::cout << this->_brain->getIdea(i) << std::endl;
}