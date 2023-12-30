#include "Contact.hpp"
#include "Agenda.h"

Contact::Contact(){}

Contact::~Contact(){}

int    Contact::new_contact()
{
    std::cout << "Enter the contact's name, please" << std::endl;
    if (this->set_contact_vars(this->first_name))
        return (1);
    std::cout << "Enter the contact's last name, please" << std::endl;
    if (this->set_contact_vars(this->last_name))
        return (1);
    std::cout << "Enter the contact's nickname, please" << std::endl;
    if (this->set_contact_vars(this->nickname))
        return (1);
    std::cout << "Enter the contact's phone, please" << std::endl;
    if (this->set_contact_vars(this->phone))
        return (1);
    std::cout << "Enter the contact's darkest secret, please" << std::endl;
    if (this->set_contact_vars(this->secret))
        return (1);
    return (0);
}

int    Contact::set_contact_vars(std::string &str)
{
    while (1)
    {
        getline(std::cin, str);
        if (std::cin.eof())
            return (1);
        else if (str == "")
            std::cout << RED << "Invalid input" << RESET << std::endl;
        else
            break ;
    }
    return (0);
}

void    Contact::print(std::string arg)
{
    std::cout << arg.substr(0, 7);
    if (arg.length() > 7)
        std::cout << ". | ";
    else
    {
        for (int i = 8 - arg.length(); i >= 0; i--)
            std::cout << " ";
        std::cout << "| ";
    }
}

void    Contact::print_preview()
{
    print(this->first_name);
    print(this->last_name);
    print(this->nickname);
    std::cout << std::endl << "--------------------------------------------" << std::endl;

}

void    Contact::print_contact()
{
    std::cout << "NAME: " + this->first_name << std::endl;
    std::cout << "LAST NAME: " + this->last_name << std::endl;
    std::cout << "NICKNAME: " + this->nickname << std::endl;
    std::cout << "PHONE NUMBER: " + this->phone << std::endl;
    std::cout << "DARKEST SECRET: " + this->secret << std::endl;
}
