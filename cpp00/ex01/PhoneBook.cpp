#include "PhoneBook.hpp"
#include "Agenda.h"

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

void    PhoneBook::add_contact()
{
    if (this->total == 8)
        this->total = 0;
    this->agenda[this->total++].new_contact();
    if (this->written < 8)
        this->written++;
}

void    PhoneBook::preview_agenda()
{
    int i = -1;

    std::cout << " ------------------------------------------- " << std::endl;
    std::cout << "|    ID    |   NAME   | LAST NA. | NICKNAME |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    while (++i < this->written)
    {
        std::cout << "|    0" << i << "    | ";
        this->agenda[i].print_preview();
    }
}

int PhoneBook::get_total()
{
    return (this->total);
}