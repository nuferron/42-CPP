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

void    Contact::full_print()
{
    std::cout << 
}