/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:42:16 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/16 19:12:42 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

#define MIN		150
#define MAX		1
#define HALF	75

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
		class	GradeTooHighException: public std::exception
		{
			public:
				const char	*what(void) const throw () {
					return ("Grade Too High");}
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				const char	*what(void) const throw () {
					return ("Grade Too Low");}
		};
	private:
		const std::string	_name;
		bool				_signed;
		const int			_reqsign;
		const int			_reqexe;
};

std::ostream &operator<<(std::ostream &out, const Form &b);

#endif
