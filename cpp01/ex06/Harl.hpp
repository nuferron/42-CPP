/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:57:39 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/09 15:44:04 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class   Harl
{
    public:
                Harl();
                ~Harl();
        void    complain(std::string level);
		void	complain(const void *ptr);
    private:
        void        _debug();
        void        _info();
        void        _warning();
        void        _error();
        std::string _code[4];
        void    (Harl::*_call[4])();
};

#endif
