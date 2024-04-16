/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:12:37 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/16 17:05:34 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

#define MIN 150
#define MAX 1
#define HALF 75

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
		int					_grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
