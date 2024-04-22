/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:11:31 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/22 11:44:16 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

void	testShrub()
{
	Intern	intern;
	Bureaucrat	b(1);
	AForm		*form;

	form = intern.makeForm("shrubbery creation", "Shrub");
	if (!form)
		return ;
	form->execute(b);
	delete form;
}

void	testRobot()
{
	Intern	intern;
	Bureaucrat	b(50);
	AForm		*form;

	form = intern.makeForm("robotomy request", "Bender");
	if (!form)
		return ;
	b.signForm(*form);
	form->execute(b);
	delete form;
}

void	testPardon()
{
	Intern	intern;
	Bureaucrat	b(5);
	AForm		*form;

	form = intern.makeForm("presidential pardon", "Zaphod");
	if (!form)
		return ;
	b.signForm(*form);
	form->execute(b);
	delete form;
}


int main()
{
	try
	{
		std::cout << "TESTING SHRUBBERY" << std::endl;
		testShrub();
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	try
	{
		std::cout << "TESTING ROBOTOMY" << std::endl;
		testRobot();
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	try
	{
		std::cout << "TESTING PARDON" << std::endl;
		testPardon();
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}
