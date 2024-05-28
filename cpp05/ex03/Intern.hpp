/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:55:20 by nuferron          #+#    #+#             */
/*   Updated: 2024/05/25 14:14:05 by nuferron         ###   ########.fr       */
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

#define TOTAL_FORMS	3
#define	FORM_NAME {"shrubbery creation", "robotomy request", "presidential pardon"}

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
