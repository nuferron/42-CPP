/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:57:25 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/09 15:35:21 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "Harl.h"

Harl::Harl()
{
    _code[0] = "DEBUG";
    _code[1] = "INFO";
    _code[2] = "WARNING";
    _code[3] = "ERROR";
    _call[0] = &Harl::_debug;
    _call[1] = &Harl::_info;
    _call[2] = &Harl::_warning;
    _call[3] = &Harl::_error;
}

Harl::~Harl() {}

void    Harl::_debug()
{
    std::cout << WHITE << "[DEBUG]" << std::endl;
    std::cout << PURPLE << "6 hours of debugging can save you 5 minutes \
	of reading documentation" << RESET << std::endl;
}

void    Harl::_info()
{
	std::cout << WHITE << "[INFO]" << std::endl;
    std::cout << CYAN << "I’ve been involved in a number of cults, both a leader and a follower. \
	You have more fun as a follower, but you make more money as a leader." << RESET <<std::endl;
}

void    Harl::_warning()
{
	std::cout << WHITE << "[WARNING]" << std::endl;
    std::cout << YELLOW << "So, have you tried turning it off and on again?" << RESET << std::endl;
}

void    Harl::_error()
{
	std::cout << WHITE << "[ERROR]" << std::endl;
    std::cout << RED << "Everything is very bad. Good luck." << RESET << std::endl;
}

void    Harl::complain(std::string level)
{
	int	i = 0;

	while (!level.empty() && i < 4 && level != Harl::_code[i])
		i++;
	if (level.empty())
		std::cout << GREEN << "[ No filter applied ]" << std::endl;
	switch (i)
	{
		case 0:
			(this->*_call[i++])();
		case 1:
			(this->*_call[i++])();
		case 2:
			(this->*_call[i++])();
		case 3:
		{
			(this->*_call[i++])();
			break ;
		}
		default:
			std::cout << GREEN << "[ This sounds like a you problem ]" << std::endl;
	}
}

void	Harl::complain(const void *ptr)
{
	if (!ptr)
		return ;
	else
		this->complain(std::string((char *)ptr));
}
