#include "PhoneBook.hpp"
#include "Agenda.h"

PhoneBook::PhoneBook()
{
	id = 0;
	total = 0;
}

PhoneBook::~PhoneBook(){}

int    PhoneBook::add_contact()
{
    if (this->id == 8)
        this->id = 0;
    if (this->agenda[this->id++].new_contact())
        return (1);
	if (this->total < 8)
        this->total++;
    return (0);
}

void    PhoneBook::preview_agenda()
{
    int i = -1;

    std::cout << " ------------------------------------------- " << std::endl;
    std::cout << "|    ID    |   NAME   | LAST NA. | NICKNAME |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    while (++i < this->total)
    {
        std::cout << "|    0" << i << "    | ";
        this->agenda[i].print_preview();
    }
}

int PhoneBook::get_total()
{
    return (this->total);
}
