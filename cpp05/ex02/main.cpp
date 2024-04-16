/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:11:31 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/16 21:40:43 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void	test_shrub()
{
	ShrubberyCreationForm	s("home");
	Bureaucrat				b("Paco", 140);
	b.signForm(s);
	std::cout << s.getTarget() << std::endl;
	//s.execute(b);
	b.executeForm(s);
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
}
