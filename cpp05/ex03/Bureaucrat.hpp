/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:12:37 by nuferron          #+#    #+#             */
/*   Updated: 2024/05/25 13:36:15 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

#define MIN 	150
#define MAX 	1
#define HALF	75

class	AForm;

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat(const std::string &name);
		Bureaucrat(int grade);
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat &b);
		int			getGrade(void) const;
		std::string	getName(void) const;
		void		increment(int n);
		void		decrement(int n);
		void		signForm(AForm &f);
		void		executeForm(const AForm &f) const;

		class GradeTooHighException;
		class GradeTooLowException;

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

class	Bureaucrat::GradeTooHighException: public std::exception
{
	public:
		const char *what(void) const throw ();
};

class	Bureaucrat::GradeTooLowException: public std::exception
{
	public:
		const char *what(void) const throw ();
};

#endif
