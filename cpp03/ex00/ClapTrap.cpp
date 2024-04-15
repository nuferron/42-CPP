/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:54:21 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/10 21:09:33 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "ClapTrap";
	this->_hit = 10;
	this->_energy = 10;
	this->_attack = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name constructor called" << std::endl;
	this->_name = name;
	this->_hit = 10;
	this->_energy = 10;
	this->_attack = 0;
}

ClapTrap::ClapTrap(ClapTrap &c)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = c;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap &c)
{
	this->_name = c.getName();
	this->_hit = c.getHit();
	this->_energy = c.getEnergy();
	this->_attack = c.getAttack();
	return (*this);
}

std::string	ClapTrap::getName(void)
{
	return (this->_name);
}

int	ClapTrap::getHit(void)
{
	return (this->_hit);
}

int	ClapTrap::getEnergy(void)
{
	return (this->_energy);
}

int	ClapTrap::getAttack(void)
{
	return (this->_attack);
}

void	ClapTrap::setAttack(unsigned int a)
{
	this->_attack = a;
}

void	ClapTrap::attack(const std::string &str)
{
	if (this->_energy == 0)
	{
		std::cout << this->_name << " is too tired to attack" << std::endl;
		return ;
	}
	if (this->_hit == 0)
	{
		std::cout << this->_name << " is dead, leave it rest in peace" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks " << str;
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
