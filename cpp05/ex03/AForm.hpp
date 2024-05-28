/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:42:16 by nuferron          #+#    #+#             */
/*   Updated: 2024/05/25 13:34:34 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

#define MIN		150
#define MAX		1
#define HALF	75

class	Bureaucrat;

class	AForm
{
	public:
		AForm();
		AForm(const AForm &f);
		AForm(const std::string name);
		AForm(int reqsign, int reqexe);
		AForm(const std::string name, int reqsign, int reqexe);
		virtual ~AForm();
		AForm	&operator=(const AForm &f);
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getReqSign(void) const;
		int			getReqExe(void) const;
		void		beSigned(const Bureaucrat &b);
		virtual	void		execute(const Bureaucrat &executor) const = 0;
		virtual std::string	getTarget(void) const = 0;

		class	GradeTooHighException;
		class	GradeTooLowException;
		class	AlreadySignedException;
		class	NotSignedException;

		private:
		const std::string	_name;
		bool				_signed;
		const int			_reqsign;
		const int			_reqexe;
};

std::ostream &operator<<(std::ostream &out, const AForm &b);

class	AForm::GradeTooHighException: public std::exception
{
	public:
		const char	*what(void) const throw ();
};

class	AForm::GradeTooLowException: public std::exception
{
	public:
		const char	*what(void) const throw ();
};

class	AForm::AlreadySignedException: public std::exception
{
	public:
		const char *what(void) const throw ();
};

class	AForm::NotSignedException: public std::exception
{
	public:
		const char	*what(void) const throw ();
};

#endif
