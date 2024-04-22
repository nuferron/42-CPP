/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:59:47 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/22 11:12:30 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &i)
{
	(void)i;
}

Intern::~Intern() {}

Intern	&Intern::operator=(const Intern &i)
{
	(void)i;
	return (*this);
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	if (name == SHRUB)
	{
		std::cout << "Intern creates " + name << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	if (name == ROBOT)
	{
		std::cout << "Intern creates " + name << std::endl;
		return (new RobotomyRequestForm(target));
	}
	if (name == PARDON)
	{
		std::cout << "Intern creates " + name << std::endl;
		return (new PresidentialPardonForm(target));
	}
	std::cerr << "Error: Invalid form name" << std::endl;
	return (NULL);
}
