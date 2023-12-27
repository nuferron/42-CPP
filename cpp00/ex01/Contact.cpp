#include "Contact.hpp"
#include "Agenda.h"

Contact::Contact(){}

Contact::~Contact(){}

void    Contact::new_contact()
{
    std::cout << "Enter the contact's name, please" << std::endl;
    getline(std::cin, this->first_name);
    std::cout << "Enter the contact's last name, please" << std::endl;
    getline(std::cin, this->last_name);
    std::cout << "Enter the contact's nickname, please" << std::endl;
    getline(std::cin, this->nickname);
    std::cout << "Enter the contact's phone number, please" << std::endl;
    getline(std::cin, this->phone);
    std::cout << "Enter the contact's darkest secret, please" << std::endl;
    getline(std::cin, this->secret);
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
    std::cout << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

}

void    Contact::print_contact()
{
    std::cout << "NAME: " + this->first_name << std::endl;
    std::cout << "LAST NAME: " + this->last_name << std::endl;
    std::cout << "NICKNAME: " + this->nickname << std::endl;
    std::cout << "PHONE NUMBER: " + this->phone << std::endl;
    std::cout << "DARKEST SECRET: " + this->secret << std::endl;
}