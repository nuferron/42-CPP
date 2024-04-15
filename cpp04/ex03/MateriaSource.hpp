/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:23:56 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/15 20:57:38 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class	MateriaSource: virtual public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &ms);
		~MateriaSource();
		MateriaSource	&operator=(const MateriaSource &ms);
		void		learnMateria(AMateria *mat);
		AMateria	*createMateria(const std::string &type);
	private:
		AMateria	*_slot[4];
};

#endif
