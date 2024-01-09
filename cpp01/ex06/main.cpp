/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:57:32 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/09 15:39:02 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "Harl.h"

int main(int argc, char **argv)
{
    Harl    msg;

	if (argc != 2)
		return (std::cout << BLUE <<"Nope. Try again." << RESET << std::endl, 1);
    msg.complain(argv[1]);
	return (1);
}
