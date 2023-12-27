#include "PhoneBook.hpp"
#include "Agenda.h"

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

void    PhoneBook::add_contact()
{
    if (this->total == 9)
        this->total = 1;
    this->agenda[this->total++].new_contact();
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
        this->agenda[i].print_var();
    }
}

void    PhoneBook::print_contact()
{
    std::cout << "NAME: ";
}