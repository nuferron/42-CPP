/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:56:02 by nuferron          #+#    #+#             */
/*   Updated: 2024/05/25 12:55:32 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Cinnamon"), _signed(0), _reqsign(50) , _reqexe(25) {}

Form::Form(const Form &f): _name(f._name), _signed(f._signed), _reqsign(f._reqsign), _reqexe(f._reqexe) {}

Form::Form(const std::string name): _name(name), _signed(0), _reqsign(50) , _reqexe(25) {}

Form::Form(int reqsign, int reqexe): _name("Cinnamon"), _signed(0), _reqsign(reqsign), _reqexe(reqexe)
{
	if (reqsign < MAX || reqexe < MAX)
		throw Form::GradeTooHighException();
	if (reqsign > MIN || reqexe > MIN)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string name, int reqsign, int reqexe): _name(name), _signed(0), _reqsign(reqsign), _reqexe(reqexe)
{
	if (reqsign < MAX || reqexe < MAX)
		throw Form::GradeTooHighException();
	if (reqsign > MIN || reqexe > MIN)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form	&Form::operator=(const Form &f)
{
	this->_signed = f._signed;
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getReqSign(void) const
{
	return (this->_reqsign);
}

int	Form::getReqExe(void) const
{
	return (this->_reqexe);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (this->_signed)
		throw Form::AlreadySignedException();
	if (b.getGrade() > this->_reqsign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &out, const Form &f)
{
	out << "Form name: " << f.getName() << std::endl;
	out << "Status: ";
	if (!f.getSigned())
		out << "Not signed" << std::endl;
	else
		out << "Signed" << std::endl;
	out << "Required grade to sign: " << f.getReqSign() << std::endl;
	out << "Required grade to execute: " << f.getReqExe();
	return (out);
}

const char	*Form::GradeTooHighException::what(void) const throw ()
{
	return ("Grade Too High");
}

const char	*Form::GradeTooLowException::what(void) const throw ()
{
	return ("Grade Too Low");
}

const char	*Form::AlreadySignedException::what(void) const throw ()
{
	return ("Form Already Signed");
}
