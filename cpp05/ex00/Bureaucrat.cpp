/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:53:07 by nuferron          #+#    #+#             */
/*   Updated: 2024/05/24 20:30:42 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Pepe"), _grade(HALF) {}

Bureaucrat::Bureaucrat(const Bureaucrat &b): _name(b._name), _grade(b._grade) {}

Bureaucrat::Bureaucrat(const std::string &name): _name(name), _grade(HALF) {}

Bureaucrat::Bureaucrat(int grade): _name("Pepe"), _grade(grade)
{
	if (this->_grade < MAX)
		throw GradeTooHighException();
	if (this->_grade > MIN)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
	if (this->_grade < MAX)
		throw GradeTooHighException();
	if (this->_grade > MIN)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &b) throw()
{
	this->_grade = b._grade;
	return (*this);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::increment(int n)
{
	int newgrade;

	newgrade = this->_grade - n;
	if (newgrade > MIN)
		throw GradeTooLowException();
	if (newgrade < MAX)
		throw GradeTooHighException();
	this->_grade = newgrade;
}

void	Bureaucrat::decrement(int n)
{
	int newgrade;

	newgrade = this->_grade + n;
	if (newgrade > MIN)
		throw GradeTooLowException();
	if (newgrade < MAX)
		throw GradeTooHighException();
	this->_grade = newgrade;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw ()
{
	return ("Grade Too High");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw ()
{
	return ("Grade Too Low");
}
