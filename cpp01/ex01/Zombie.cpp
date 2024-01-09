/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:52:49 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/09 15:49:42 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie() {};

Zombie::~Zombie()
{
    std::cout << this->_name << " is definitely dead" << std::endl;
};

void    Zombie::announce()
{
    std::cout << this->_name + ": BraiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string str)
{
    this->_name = str;
}
