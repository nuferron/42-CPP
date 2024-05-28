/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:59:47 by nuferron          #+#    #+#             */
/*   Updated: 2024/05/25 14:17:05 by nuferron         ###   ########.fr       */
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
	int	i = 0;
	const char *forms[TOTAL_FORMS] = FORM_NAME;

	while (i < 3 && name != forms[i])
		i++;
	switch (i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			std::cerr << "Error: Invalid form name" << std::endl;
	}
	return (NULL);
}
