#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
    this->_type = weapon;
}

Weapon::~Weapon() {}

std::string Weapon::getType() const
{
    return (this->_type);
}

void    Weapon::setType(std::string &str)
{
    this->_type = str;
}