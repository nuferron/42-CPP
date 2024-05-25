/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:11:31 by nuferron          #+#    #+#             */
/*   Updated: 2024/05/25 12:56:25 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void	test_constructor()
{
	Form	f(180, 3);

	std::cout << f << std::endl;
}

void	test_beSigned()
{
	Bureaucrat	b(100);
	Form		f;

	std::cout << b << std::endl;
	f.beSigned(b);
	std::cout << f << std::endl;
}

void	test_signForm()
{
	Bureaucrat	b(100);
	Form		f(99, 2);

	std::cout << b << std::endl;
	b.signForm(f);
	std::cout << f << std::endl;
}

void	test_signedTwice()
{
	Bureaucrat	b(50);
	Bureaucrat	b2("Manfred", 50);
	Form		f(100, 2);

	std::cout << b << std::endl << b2 << std::endl;
	std::cout << std::endl << f << std::endl;
	b.signForm(f);
	std::cout << std::endl << f << std::endl;
	b2.signForm(f);
}

int main()
{
	try
	{
		std::cout << RED << "TESTING CONSTRUCTOR" << RESET << std::endl;
		test_constructor();
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << RED << "TESTING BE_SIGNED" << RESET << std::endl;
		test_beSigned();
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << RED << "TESTING SIGN_FORM" << RESET << std::endl;
		test_signForm();
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << RED << "TESTING SIGNED TWICE" << RESET << std::endl;
		test_signedTwice();
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
