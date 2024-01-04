/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:45:57 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/04 19:46:42 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie(std::string str)
{
    _name = str;
};

Zombie::~Zombie()
{
    std::cout << this->_name << " is definitely dead" << std::endl;
};

void    Zombie::announce()
{
    std::cout << this->_name + ": BraiiiinnnzzzZ..." << std::endl;
}
