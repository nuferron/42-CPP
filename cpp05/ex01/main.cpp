/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:11:31 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/16 19:29:04 by nuferron         ###   ########.fr       */
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

int main()
{
	try
	{
		std::cout << "TESTING CONSTRUCTOR" << std::endl;
		test_constructor();
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "TESTING BE_SIGNED" << std::endl;
		test_beSigned();
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "TESTING SIGN_FORM" << std::endl;
		test_signForm();
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
