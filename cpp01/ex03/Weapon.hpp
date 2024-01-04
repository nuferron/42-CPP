#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class   Weapon
{
    public:
        Weapon(std::string weapon);
        ~Weapon();
		std::string getType() const;
        void        setType(std::string str);
    private:
        std::string _type;
};

#endif
