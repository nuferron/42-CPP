#include "Agenda.h"
#include "PhoneBook.hpp"

/*It takes an integer as user input nd tries to print the contact's information
related to that index. If the input is not an integer, it will display an error message.
Ctrl-D finishes the program (it's closes fd -> eof).*/
void    search(PhoneBook &phone_book)
{
    int num;

    phone_book.preview_agenda();
    std::cout << "What contact would you like to see?" << std::endl;
    std::cin >> num;
    if (std::cin.eof())
        return ;
    if (!std::cin)
        std::cout << RED << "Input is not an integer" << RESET << std::endl;
    else if (num < 0 || num >= phone_book.get_total())
        std::cout << RED << "Invalid index" << RESET << std::endl;
    else
        phone_book.agenda[num].print_contact();
    //std::cin.clear();
    std::cin.ignore(1, '\n');
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
        if (std::cin.eof())
            return(0);
        if (input == "ADD")
            phone_book.add_contact();
        else if (input == "SEARCH")
            search(phone_book);
        else if (input == "EXIT")
        {
            std::cout << GREEN << "Thank you for using Agenda, see you soon!" << RESET << std::endl;
            return(0);
        }
        else
            std::cout << RED << "The only valid options are: \"ADD\", \"SEARCH\" and \"EXIT\" (this program is case-sensitive)" << RESET << std::endl;
        if (!std::cin)
            return(0);
        if (input == "ADD" || input == "SEARCH" || input == "EXIT")
        {
            std::cout << std::endl << "What else would you like to do?" << std::endl;
            std::cout << "\tADD\tSEARCH\t   EXIT" << std::endl;
        }
    }
    return (1);
}