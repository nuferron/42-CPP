#include "Zombie.h"
#include <cstdlib>

Zombie  *zombieHorde(int n, std::string name)
{
    Zombie  *horde;

    try
    {
        horde = new Zombie[n];
    }
    catch (std::bad_alloc& ba)
    {
        std::cout << RED << "The horde has been eliminated before you could even see it coming! Better luck next time" << std::endl;
        exit(1);
    }
    for (int i = 0; i < n; i++)
        horde[i].set_name(name);
    return (horde);
}