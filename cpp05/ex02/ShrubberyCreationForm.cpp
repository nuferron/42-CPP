/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:13:11 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/16 21:41:22 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm(145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s): AForm(s.getName(), s.getReqSign(), s.getReqExe()) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSigned())
		throw AForm::NotSignedException();
	if (this->getReqExe() < executor.getGrade())
		throw AForm::GradeTooLowException();
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
