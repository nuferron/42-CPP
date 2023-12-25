#include "PhoneBook.hpp"
#include "Agenda.h"

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

void    PhoneBook::add_contact()
{
    if (this->id == 9)
        this->id = 1;
    this->agenda[this->id].new_contact();
}

void    PhoneBook::preview_agenda()
{
    std::cout << " ------------------------------------------- " << std::endl;
    std::cout << "|    ID    |   NAME   | LAST NA. | NICKNAME |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|    0" << this->id << "    ";
    //std::cout << "| " << this->agenda[0].first_name << " |";
}