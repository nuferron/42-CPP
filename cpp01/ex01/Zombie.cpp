#include "Zombie.h"

Zombie::Zombie() {};

Zombie::~Zombie()
{
    std::cout << this->name << " is definitely dead" << std::endl;
};

void    Zombie::announce()
{
    std::cout << this->name + ": BraiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string str)
{
    this->name = str;
}