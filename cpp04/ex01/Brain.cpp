#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(const Brain &b)
{
    this->_ideas = b.getIdeas();
    std::cout << "Brain: Copy constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain: Destructor called" << std::endl;
}

Brain   &Brain::operator=(const Brain &b)
{
    this->_ideas = b.getIdeas();
    return (*this);
}

std::string Brain::getIdeas(void)
{
    return (this->_ideas);
}