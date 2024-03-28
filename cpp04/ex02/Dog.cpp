#include "Dog.hpp"

Dog::Dog(): Animal::Animal("Dog"), _type("Dog")
{
    this->_brain = new Brain;
    std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(Dog &d): Animal::Animal("Dog")
{
    this->_brain = d._brain;
    std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog: Destructor called" << std::endl;
}

Dog &Dog::operator=(Dog &d)
{
    if (this->_brain)
        delete _brain;
    this->_brain = d._brain;
    return (*this);
}

std::string Dog::getType(void) const
{
    return(this->_type);
}

void    Dog::setIdea(const std::string &str)
{
    this->_brain->setIdea(str);
}

void    Dog::makeSound(void) const
{
    std::cout << "Woof arf" << std::endl;
}

void    Dog::printIdeas(void) const
{
    int id = this->_brain->getId();
    for (int i = 0; i < id; i++)
        std::cout << this->_brain->getIdea(i) << std::endl;
}