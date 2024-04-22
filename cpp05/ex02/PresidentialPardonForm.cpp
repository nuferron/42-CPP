/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:13:11 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/22 11:53:12 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("zaphod", 25, 5), _target("zaphod") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &s): AForm(s.getName(), s.getReqSign(), s.getReqExe()) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &s)
{
	this->_target = s._target;
	return (*this);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSigned())
	{
		std::cerr << "Execution denied: ";
		throw AForm::NotSignedException();
	}
	if (this->getReqExe() < executor.getGrade())
	{
		std::cerr << "Execution denied: ";
		throw AForm::GradeTooLowException();
	}
	std::cout << this->_target + " has been pardoned by " << "Zaphod Beeblebrox" << std::endl;
}
