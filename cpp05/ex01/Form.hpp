/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:42:16 by nuferron          #+#    #+#             */
/*   Updated: 2024/05/25 12:50:36 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

#define MIN		150
#define MAX		1
#define HALF	75
#define RED		"\033[1;31m"
#define RESET	"\033[0m"

class	Bureaucrat;

class	Form
{
	public:
		Form();
		Form(const Form &f);
		Form(const std::string name);
		Form(int reqsign, int reqexe);
		Form(const std::string name, int reqsign, int reqexe);
		~Form();
		Form	&operator=(const Form &f);
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getReqSign(void) const;
		int			getReqExe(void) const;
		void		beSigned(const Bureaucrat &b);

		class	GradeTooHighException;
		class	GradeTooLowException;
		class	AlreadySignedException;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_reqsign;
		const int			_reqexe;
};

std::ostream &operator<<(std::ostream &out, const Form &b);


class	Form::GradeTooHighException: public std::exception
{
	public:
		const char	*what(void) const throw ();
};

class	Form::GradeTooLowException: public std::exception
{
	public:
		const char	*what(void) const throw ();
};

class	Form::AlreadySignedException: public std::exception
{
	public:
		const char *what(void) const throw ();
};

#endif
