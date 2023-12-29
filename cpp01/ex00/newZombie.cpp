#include "Zombie.h"

Zombie*     new_zombie(std::string name)
{
    Zombie  *zombie;

    zombie = new Zombie(name);
    return (zombie);
}