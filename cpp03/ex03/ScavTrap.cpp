#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("pepe", _cth, _cte, _cta)
{
	std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name, _cth, _cte, _cta)
{
	std::cout << "ScavTrap: String constructor called: " << this->getName() << " is alive now!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &s): ClapTrap(s.getName(), s.getHit(), s.getEnergy(), s.getAttack())
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &s)
{
	this->_name = s.getName();
	this->_hit = s.getHit();
	this->_energy = s.getEnergy();
	this->_attack = s.getAttack();
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called: " << this->getName() << " no longer exists" << std::endl;
}

void	ScavTrap::attack(const std::string &str)
{
	if (this->_hit == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead, leave it rest in peace" << std::endl;
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "No energy left. ScavTrap " << this->_name << " must accept its fate." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << str;
	std::cout << ", causing " << this->_attack << " points of damage!" << std::endl;
	this->_energy--;
}

void	ScavTrap::guardGate(void) const
{
	std::cout << "Gate keeper mode status: Activated" << std::endl;
}
