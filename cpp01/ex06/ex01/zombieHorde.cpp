/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:54:08 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/04 19:54:12 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <cstdlib>

Zombie  *zombieHorde(int n, std::string name)
{
    Zombie  *horde;

    try
    {
        horde = new Zombie[n];
    }
    catch (std::bad_alloc& ba)
    {
        std::cout << RED << "The horde has been eliminated before you could even see it coming! Better luck next time" << std::endl;
        exit(1);
    }
    for (int i = 0; i < n; i++)
        horde[i].set_name(name);
    return (horde);
}
