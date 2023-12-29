#include "Zombie.h"

Zombie::Zombie(std::string str)
{
    name = str;
};

Zombie::~Zombie()
{
    std::cout << this->name << " is definitely dead" << std::endl;
};

void    Zombie::announce()
{
    std::cout << this->name + ": BraiiiinnnzzzZ..." << std::endl;
}