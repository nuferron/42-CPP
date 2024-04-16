/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:11:31 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/16 17:36:00 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	test_decrement()
{
	Bureaucrat	b;

	b.decrement(75);
	std::cout << b << std::endl;
	b.decrement(1);
}

void	test_increment()
{
	Bureaucrat	b;

	b.increment(74);
	std::cout << b << std::endl;
	b.increment(1);
}

void	test_constructor()
{
	Bureaucrat	b(0);

	std::cout << b << std::endl;
}

void	test_negatives()
{
	Bureaucrat	b("Manfred", -3);

	std::cout << b << std::endl;
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
		std::cout << "TESTING DECREMENT FUNCTION" << std::endl;
		test_decrement();
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << "TESTING INCREMENT FUNCTION" << std::endl;
		test_increment();
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << "TESTING NEGATIVES" << std::endl;
		test_negatives();
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
