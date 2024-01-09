/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:48:15 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/09 15:48:17 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon): _type(weapon) {}

Weapon::~Weapon() {}

std::string Weapon::getType() const
{
    return (this->_type);
}

void    Weapon::setType(std::string str)
{
    this->_type = str;
}
