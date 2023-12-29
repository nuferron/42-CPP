#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include "Zombie.hpp"

#define RED         "\033[1;31m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define BLUE        "\033[1;34m"
#define PURPLE      "\033[1;35m"
#define CYAN        "\033[1;36m"
#define WHITE       "\033[1;37m"
#define RESET       "\033[0m"

Zombie* new_zombie(std::string name);
void    randomChump(std::string name);

#endif