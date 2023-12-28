#include "Agenda.h"
#include "PhoneBook.hpp"

int    search(PhoneBook &phone_book)
{
    int num;

    phone_book.preview_agenda();
    std::cout << "What contact would you like to see?" << std::endl;
    std::cin >> num;
    if (!std::cin)
        return (1);
    else if (num < 0 || num >= phone_book.get_total())
        std::cout << RED << "Invalid index" << RESET << std::endl;
    else
        phone_book.agenda[num].print_contact();
    std::cin.clear();
    std::cin.ignore(1, '\n');
    return (0);
}

int main(void)
{
    PhoneBook phone_book;
    std::string  input;

    std::cout << "Hi! Try one of these options:" << std::endl;
    std::cout << "\tADD\tSEARCH\t   EXIT" << std::endl;
    while (1)
    {
        getline(std::cin, input);
        if (!std::cin)
            return(0);
        else if (input == "ADD")
        {
            phone_book.add_contact();
        }
        else if (input == "SEARCH")
        {
            if (search(phone_book))
                return (1);
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
            std::cout << std::endl << "What else would you like to do?" << std::endl;
            std::cout << "\tADD\tSEARCH\t   EXIT" << std::endl;
        }
    }
    return (1);
}