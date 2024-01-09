/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:44:27 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/09 15:44:28 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl    msg;

    msg.complain("ERROR");
    msg.complain("");
    msg.complain((void *)0);
    msg.complain(NULL);
    msg.complain("WARNING");
    msg.complain("INFO");
	msg.complain("DEBUG");
}
