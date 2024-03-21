#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Wall-E", 100, 100, 30)
{
	std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap: String constructor called: " << this->getName() << " is alive now!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &s): ClapTrap(s.getName(), s.getHit(), s.getEnergy(), s.getAttack())
{
	std::cout << "FragTrap: Copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &s)
{
	this->_name = s.getName();
	this->_hit = s.getHit();
	this->_energy = s.getEnergy();
	this->_attack = s.getAttack();
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called: " << this->getName() << " no longer exists" << std::endl;
}

void	FragTrap::attack(const std::string &str)
{
	if (this->_hit == 0)
	{
		std::cout << "FragTrap " << this->_name << " is dead, leave it rest in peace" << std::endl;
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "No energy left. FragTrap " << this->_name << " must accept its fate." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << str;
	std::cout << ", causing " << this->_attack << " points of damage!" << std::endl;
	this->_energy--;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->_name << " requests a high fives. Waiting for confirmation..." << std::endl;
}
