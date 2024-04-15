#include "Dog.hpp"

Dog::Dog(): AAnimal::AAnimal("Dog"), _type("Dog")
{
    this->_brain = new Brain;
    std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(Dog &d): AAnimal::AAnimal("Dog")
{
    this->_brain = new Brain(*d._brain);
    std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog::~Dog()
{
	if (this->_brain)
    	delete this->_brain;
    std::cout << "Dog: Destructor called" << std::endl;
}

Dog &Dog::operator=(Dog &d)
{
    *this->_brain = *d._brain;
    return (*this);
}

std::string Dog::getType(void) const
{
    return (this->_type);
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
    if (!id)
    {
        std::cout << "This " << this->_type << " has no ideas yet!" << std::endl;
        return ;
    }
    for (int i = 0; i < id; i++)
        std::cout << this->_brain->getIdea(i) << std::endl;
}
