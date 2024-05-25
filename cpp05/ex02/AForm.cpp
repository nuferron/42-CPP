/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:56:02 by nuferron          #+#    #+#             */
/*   Updated: 2024/05/25 13:27:04 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Cinnamon"), _signed(0), _reqsign(50) , _reqexe(25) {}

AForm::AForm(const AForm &f): _name(f._name), _signed(f._signed), _reqsign(f._reqsign), _reqexe(f._reqexe) {}

AForm::AForm(const std::string name): _name(name), _signed(0), _reqsign(50) , _reqexe(25) {}

AForm::AForm(int reqsign, int reqexe): _name("Cinnamon"), _signed(0), _reqsign(reqsign), _reqexe(reqexe)
{
	if (reqsign < MAX || reqexe < MAX)
		throw AForm::GradeTooHighException();
	if (reqsign > MIN || reqexe > MIN)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string name, int reqsign, int reqexe): _name(name), _signed(0), _reqsign(reqsign), _reqexe(reqexe)
{
	if (reqsign < MAX || reqexe < MAX)
		throw AForm::GradeTooHighException();
	if (reqsign > MIN || reqexe > MIN)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm	&AForm::operator=(const AForm &f)
{
	this->_signed = f._signed;
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getReqSign(void) const
{
	return (this->_reqsign);
}

int	AForm::getReqExe(void) const
{
	return (this->_reqexe);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (this->_signed)
		throw AForm::AlreadySignedException();
	if (b.getGrade() > this->_reqsign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &out, const AForm &f)
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

const char	*AForm::GradeTooHighException::what(void) const throw ()
{
	return ("Grade Too High");
}

const char	*AForm::GradeTooLowException::what(void) const throw ()
{
	return ("Grade Too Low");
}

const char	*AForm::AlreadySignedException::what(void) const throw ()
{
	return ("Form Already Signed");
}

const char	*AForm::NotSignedException::what(void) const throw ()
{
	return ("Form Not Signed");
}
