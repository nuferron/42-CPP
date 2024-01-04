/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:48:01 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/04 19:48:03 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie*     new_zombie(std::string name)
{
    Zombie  *zombie;

    zombie = new Zombie(name);
    return (zombie);
}
