/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:20:45 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/15 20:58:18 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class AMateria;

class	IMateriaSource
{
	public:
		virtual	~IMateriaSource() {};
		virtual void		learnMateria(AMateria *) = 0;
		virtual AMateria	*createMateria(const std::string &type) = 0;
};

#endif
