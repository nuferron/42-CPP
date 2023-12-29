#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
    public:
                Zombie();
                ~Zombie();
        void    announce();
        void    set_name(std::string name);
    private:
        std::string name;
};

#endif