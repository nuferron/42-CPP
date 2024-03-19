/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:54:21 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/19 16:10:32 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "ClapTrap";
	this->_hit = 10;
	this->_energy = 10;
	this->_attack = 10;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hit = 10;
	this->_energy = 10;
	this->_attack = 10;
}

ClapTrap::ClapTrap(ClapTrap &c)
{
	*this = c;
}

ClapTrap::~ClapTrap() {}

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

void	ClapTrap::setHit(unsigned int h)
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
	std::cout << "ClapTrap " << this->_name << " attacks " << str;
	std::cout << ", causing " << this->_attack << " points of damage!" << std::endl;
	this->_energy--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Oh, no! " << this->_name << " has received " << amount << "points of damage! His current life is: " << this->_hit << std::endl;
	this->_hit -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_name << " has repaired itself! His current life is: " << this->_hit << std::endl;
	this->_hit += amount;
	this->_energy--;
}
