#include "Zombie.h"

int main()
{
    Zombie  *saved_zombie;

    saved_zombie = new_zombie("delulu");
    randomChump("telele");
    saved_zombie->announce();
    delete saved_zombie;
    return (0);
}