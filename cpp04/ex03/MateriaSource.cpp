/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:30:40 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/16 11:52:23 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &ms)
{
	*this = ms;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i])
			delete _slot[i];
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &ms)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i])
			delete _slot[i];
		this->_slot[i] = ms._slot[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *mat)
{
	int i = 0;

	while (i < 4 && this->_slot[i])
		i++;
	if (i == 4)
	{
		std::cout << "No more materias can be learned! ";
		std::cout << "Try using another Materia Source" << std::endl;
		return ;
	}
	this->_slot[i] = mat;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	int i = 0;

	while (i < 4 && this->_slot[i])
	{
		if (this->_slot[i]->getType() == type)
			break ;
		i++;
	}
	if (i == 4 || !this->_slot[i])
	{
		std::cout << "Unknown materia " + type + ". Please, try again" << std::endl;
		return (NULL);
	}
	return (this->_slot[i]->clone());
}
