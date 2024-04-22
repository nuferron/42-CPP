/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:31:53 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/22 11:52:49 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("robot", 72, 45), _target("robot") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm(target, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &s): AForm(s.getName(), s.getReqSign(), s.getReqExe()) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &f)
{
	this->_target = f._target;
	return (*this);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	static bool	rand = 0;
	if (!this->getSigned())
	{
		std::cerr << "Exeution denied: ";
		throw AForm::NotSignedException();
	}
	if (this->getReqExe() < executor.getGrade())
	{
		std::cerr << "Exeution denied: ";
		throw AForm::GradeTooLowException();
	}
	std::cout << "Bzzzz rrrrr bzzzzz" << std::endl;
	if (rand)
		std::cout << "Oh, no, the robotomy failed" << std::endl;
	else
		std::cout << this->_target << " has been successfully robotomized!" << std::endl;
	rand = !rand;
}
