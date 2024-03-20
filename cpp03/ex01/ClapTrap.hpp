/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:45:33 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/19 16:52:21 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &c);
		ClapTrap(const std::string name, unsigned int h, unsigned int e, unsigned int a);
		~ClapTrap();
		ClapTrap	&operator=(const ClapTrap &c);
		virtual void	attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName(void) const;
		int		getHit(void) const;
		int		getEnergy(void) const;
		int		getAttack(void) const;
		void		setName(std::string name);
		void		setHit(unsigned int h);
		void		setEnergy(unsigned int e);
		void		setAttack(unsigned int a);
	protected:
		std::string	_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attack;
};

#endif
