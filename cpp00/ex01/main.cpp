#include "Agenda.h"
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phone_book;
    std::string  input;

    std::cout << "Hi! Try one of these options:" << std::endl;
    std::cout << "\tADD\tSEARCH\t   EXIT" << std::endl;
    while (1)
    {
        std::cin >> input;
        std::cout << CYAN << input << RESET << std::endl;
        if (!std::cin)
            return(0);
        else if (input == "ADD")
        {
            phone_book.add_contact();
        }
        else if (input == "SEARCH")
        {
            phone_book.preview_agenda();
            std::cout << "What contact would you like to see?" << std::endl;
            std::cin >> input;
            if (!std::cin)
                return (1);
            else
                std::cout << PURPLE << input << RESET << std::endl;
}
        else if (input == "EXIT")
        {
            std::cout << GREEN << "Thank you for using Agenda, see you soon!" << RESET << std::endl;
            return(0);
        }
        else
            std::cout << RED << "The only valid options are: \"ADD\", \"SEARCH\" and \"EXIT\" (this program is case-sensitive)" << RESET << std::endl;
        if (input == "ADD" || input == "SEARCH" || input == "EXIT")
        {
            std::cout << "What else would you like to do?" << std::endl;
            std::cout << "\tADD\tSEARCH\t   EXIT" << std::endl;
        }
    }
    return (1);
}