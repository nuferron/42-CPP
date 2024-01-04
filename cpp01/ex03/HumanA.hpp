#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon &_weapon);
        ~HumanA();
        void    attack();
    private:
        Weapon      &_weapon;
        std::string _name;
};

#endif
