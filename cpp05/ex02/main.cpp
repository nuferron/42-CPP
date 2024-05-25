/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:11:31 by nuferron          #+#    #+#             */
/*   Updated: 2024/05/25 13:26:03 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test_shrub()
{
	ShrubberyCreationForm	s("home");
	Bureaucrat				b("Paco", 140);
	b.signForm(s);
	b.signForm(s);
	std::cout << s.getTarget() << std::endl;
	//s.execute(b);
	b.executeForm(s);
}

void	test_robot()
{
	RobotomyRequestForm	r;
	Bureaucrat			b("Manfred", 45);
	b.signForm(r);
	std::cout << r.getTarget() << std::endl;
	//r.execute(b);
	b.executeForm(r);
	b.executeForm(r);
	b.executeForm(r);
}

void	test_pardon()
{
	PresidentialPardonForm	p;
	Bureaucrat				b("Grisham", 5);

	b.signForm(p);
	//p.execute(b);
	b.executeForm(p);
}

int main()
{
	try
	{
		std::cout << "TESTING SHRUBBERY" << std::endl;
		test_shrub();
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "TESTING ROBOTOMY" << std::endl;
		test_robot();
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "TESTING PARDON" << std::endl;
		test_pardon();
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
