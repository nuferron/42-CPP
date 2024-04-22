/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:55:20 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/16 23:44:02 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define SHRUB	"shrubbery creation"
#define ROBOT	"robotomy request"
#define PARDON	"presidential pardon"

class AForm;

class	Intern
{
	public:
		Intern();
		Intern(const Intern &i);
		~Intern();
		Intern	&operator=(const Intern &i);
		AForm	*makeForm(const std::string &name, const std::string &target);
};

#endif
