/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:48:19 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/09 15:48:21 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class   Weapon
{
    public:
        Weapon(std::string weapon);
        ~Weapon();
		std::string getType() const;
        void        setType(std::string str);
    private:
        std::string _type;
};

#endif
