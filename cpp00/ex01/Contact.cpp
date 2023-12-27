#include "Contact.hpp"
#include "Agenda.h"

Contact::Contact(){}

Contact::~Contact(){}

void    Contact::new_contact()
{
    std::cout << "Enter the contact's name, please" << std::endl;
    std::cin >> this->first_name;
    std::cout << "Enter the contact's last name, please" << std::endl;
    std::cin >> this->last_name;
    std::cout << "Enter the contact's nickname, please" << std::endl;
    std::cin >> this->nickname;
    std::cout << "Enter the contact's phone number, please" << std::endl;
    std::cin >> this->phone;
    std::cout << "Enter the contact's darkest secret, please" << std::endl;
    std::cin >> this->secret;
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

void    Contact::print_var()
{
    print(this->first_name);
    print(this->last_name);
    print(this->nickname);
    std::cout << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

}