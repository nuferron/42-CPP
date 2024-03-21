#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("Frankenstein_clap_name", FragTrap::_cth, ScavTrap::_cte, ScavTrap::_cta)
{
	this->_name = "Frankenstein";
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name", FragTrap::_cth, ScavTrap::_cte, ScavTrap::_cta)
{
	this->_name = name;
	std::cout << "DiamondTrap: Name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d): ClapTrap(d), ScavTrap(d), FragTrap(d)
{
	this->_name = d.getName();
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &d)
{
	this->_name = d.getName();
	this->_hit = d.getHit();
	this->_energy = d.getEnergy();
	this->_attack = d.getAttack();
	return (*this);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "Diamond name: " << this->_name << std::endl;
	std::cout << "Clap name: " << this->ClapTrap::_name << std::endl;
}
