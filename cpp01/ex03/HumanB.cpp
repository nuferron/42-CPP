#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	if (!this->_weapon)
		std::cout << this->_name << " doesn't have any weapons! He/She attacks with his/her bare hands" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
