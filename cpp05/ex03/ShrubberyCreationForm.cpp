/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:13:11 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/22 11:47:00 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("shrub", 145, 137), _target("shrub") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm(target, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s): AForm(s.getName(), s.getReqSign(), s.getReqExe()) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
	this->_target = s._target;
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
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
	std::ofstream shrub(this->_target + "_shrubbery");
	if (shrub.fail())
	{
		std::cerr << "ERROR: Couldn't create file" << std::endl;
		return ;
	}
	shrub << "              * *    " << std::endl;
	shrub << "           *    *  *" << std::endl;
	shrub << "      *  *    *     *  *" << std::endl;
	shrub << "     *     *    *  *    *" << std::endl;
	shrub << " * *   *    *    *    *   *" << std::endl;
	shrub << " *     *  *    * * .#  *   *" << std::endl;
	shrub << " *   *     * #.  .# *   *" << std::endl;
	shrub << "  *     \"#.  #: #\" * *    *" << std::endl;
	shrub << " *   * * \"#. ##\"       *" << std::endl;
	shrub << "   *       \"###" << std::endl;
	shrub << "             \"##" << std::endl;
	shrub << "              ##." << std::endl;
	shrub << "              .##:" << std::endl;
	shrub << "              :###" << std::endl;
	shrub << "              ;###" << std::endl;
	shrub << "            ,####." << std::endl;
	shrub << "/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\" << std::endl;
	shrub.close();
}
