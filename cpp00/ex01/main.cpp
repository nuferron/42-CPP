#include "Agenda.h"
#include "PhoneBook.hpp"

/*It takes a string, skips the whitespaces (at the beginning and at the end of the string)
and returns -1 if the input is invalid and the actual input if it is valid*/
int search_id(std::string str)
{
    int i = 0;
    int len = str.length() - 1;

    if (str[0] == '-')
        return (-1);
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
            || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
            i++;
    while (str[len] == ' ' || str[len] == '\n' || str[len] == '\t'
            || str[len] == '\v' || str[len] == '\f' || str[len] == '\r')
            len--;
    while (str[i] == '0')
        i++;
    if (len - i > 1)
        return (-1);
    if (len - i == -1)
        return (0);
    return (str[i] - '0');
}

/*It takes an integer as user input and tries to print the contact's information
related to that index. If the input is not an integer, it will display an error message.
Ctrl-D finishes the program (it's closes fd -> eof).*/
int    search(PhoneBook &phone_book)
{
    std::string str;
    int         num;

    if (!phone_book.get_total())
    {
        std::cout << PURPLE << "There are no contacts to show yet!" << RESET << std::endl;
        return (0);
    }
    phone_book.preview_agenda();
    std::cout << "What contact's details would you like to see?" << std::endl;
    getline(std::cin, str);
    num = search_id(str);
    if (std::cin.eof())
        return (1);
    if (!std::cin)
        std::cout << RED << "Input is not an integer" << RESET << std::endl;
    else if (num < 0 || num >= phone_book.get_total())
        std::cout << RED << "Invalid index" << RESET << std::endl;
    else
        phone_book.agenda[num].print_contact();
    return (0);
}

int main(void)
{
    PhoneBook phone_book;
    std::string  input;

    std::cout << "Hi! Try one of these options:" << std::endl;
    std::cout << WHITE << OPTIONS << RESET << std::endl;
    while (1)
    {
        getline(std::cin, input);
        if (std::cin.eof())
            break ;
        if (input == "ADD" && phone_book.add_contact())
            break ;
        else if (input == "SEARCH" && search(phone_book))
            break ;
        else if (input == "EXIT")
            return (std::cout << GREEN << EXIT_MSG << std::endl, 0);
        if (input == "ADD" || input == "SEARCH" || input == "EXIT")
        {
            std::cout << std::endl << "What else would you like to do?" << std::endl;
            std::cout << WHITE << OPTIONS << RESET << std::endl;
        }
        else
            std::cout << RED << ERR_OPTIONS << RESET << std::endl;
    }
    return (1);
}