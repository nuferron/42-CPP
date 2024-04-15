#include "Brain.hpp"

Brain::Brain(): _id(0)
{
    std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(Brain &b): _id(b._id)
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
    for (int i = 0; i < b._id; i++)
        this->_ideas[i] = b._ideas[i];
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
