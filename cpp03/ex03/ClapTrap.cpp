/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:54:21 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/19 17:23:57 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap: Default constructor called" << std::endl;
	this->_name = "ClapTrap";
	this->_hit = 10;
	this->_energy = 10;
	this->_attack = 0;
}

ClapTrap::ClapTrap(const std::string name)
{
	std::cout << "ClapTrap: Name constructor called" << std::endl;
	this->_name = name;
	this->_hit = 10;
	this->_energy = 10;
	this->_attack = 0;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	std::cout << "ClapTrap: Copy constructor called" << std::endl;
	*this = c;
}

ClapTrap::ClapTrap(const std::string name, unsigned int h, unsigned int e, unsigned int a)
{
	std::cout << "ClapTrap: Contructor with all variables" << std::endl;
	this->_name = name;
	this->_hit = h;
	this->_energy = e;
	this->_attack = a;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &c)
{
	this->_name = c.getName();
	this->_hit = c.getHit();
	this->_energy = c.getEnergy();
	this->_attack = c.getAttack();
	return (*this);
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHit(void) const
{
	return (this->_hit);
}

int	ClapTrap::getEnergy(void) const
{
	return (this->_energy);
}

int	ClapTrap::getAttack(void) const
{
	return (this->_attack);
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void ClapTrap::setHit(unsigned int h)
{
	this->_hit = h;
}

void	ClapTrap::setEnergy(unsigned int e)
{
	this->_energy = e;
}

void	ClapTrap::setAttack(unsigned int a)
{
	this->_attack = a;
}

void	ClapTrap::attack(const std::string &str)
{
	if (this->_hit == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead, leave it rest in peace" << std::endl;
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "No energy left. Claptrap " << this->_name << " must accept its fate." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << str;
	std::cout << ", causing " << this->_attack << " points of damage!" << std::endl;
	this->_energy--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit == 0)
	{
		std::cout << this->_name << " is already dead... Nothing happened" << std::endl;
		return ;
	}
	std::cout << "Oh, no! " << this->_name << " has received " << amount << " points of damage! ";
	if (this->_hit < this->_hit - amount)
	{
		this->_hit = 0;
		std::cout << "It's dead, now. RIP " << this->_name << std::endl;
		return ;
	}
	this->_hit -= amount;
	std::cout << "His current life is: " << this->_hit << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy == 0)
	{
		std::cout << "No energy left. " << this->_name << " must accept its fate." << std::endl;
		return ;
	}
	this->_energy--;
	if (this->_hit == 0)
	{
		std::cout << this->_name << " is dead! Nothing can be done..." << std::endl;
		return ;
	}
	this->_hit += amount;
	std::cout << this->_name << " has repaired itself! His current life is: " << this->_hit << std::endl;
}
