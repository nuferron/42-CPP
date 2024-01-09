/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:47:48 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/04 19:51:20 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

static int get_name(std::string &name, std::string mem)
{
    std::cout << YELLOW << "Insert a name for the zombie saved in the " << mem << " memory" << RESET << std::endl;
    getline(std::cin, name);
    if (std::cin.eof())
        return (1);
    if (name == "")
    {
        if (mem == "heap")
            name = "HEAP ZOMBIE";
        else
            name = "STACK ZOMBIE";
    }
    return (0);
}

int main()
{
    Zombie  *saved_zombie;
    std::string heap_name;
    std::string stack_name;
    
    if (get_name(heap_name, "heap"))
        return (1);
    if (get_name(stack_name, "stack"))
        return (1);
    std::cout << std::endl;
    saved_zombie = new_zombie(heap_name);
    randomChump(stack_name);
    saved_zombie->announce();
    delete saved_zombie;
    return (0);
}
