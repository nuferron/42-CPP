#include "Brain.hpp"

Brain::Brain()
{
    this->_id = 0;
    std::cout << "Brain: Default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = "No thinking, only doing";
}

Brain::Brain(Brain &b)
{
    *this = b;
    std::cout << "Brain: Copy constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain: Destructor called" << std::endl;
}

Brain   &Brain::operator=(Brain &b)
{
    this->_id = b._id;
    for (int i = 0; i < this->_id; i++)
        this->_ideas[i] = b.getIdea(i);
    return (*this);
}

std::string Brain::getIdea(int id) const
{
    return (this->_ideas[id]);
}

int Brain::getId(void) const
{
    return (this->_id);
}

void    Brain::setIdea(const std::string &str)
{
    if (this->_id == 100)
        _id = 0;
    this->_ideas[this->_id] = str;
    this->_id++;
}