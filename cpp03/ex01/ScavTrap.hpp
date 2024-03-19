/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:24:14 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/19 18:57:09 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class	ScavTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &s);
		~ScavTrap();
	private
};

#endif
