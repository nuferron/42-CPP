#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB();
        ~HumanB();
        void    attack();
    private:
        std::string _name;
        Weapon      &_weapon;
};

#endif