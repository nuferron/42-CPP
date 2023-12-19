#include "Agenda.h"

int main(int argc, char **argv)
{
    //Contact     contact;
    //PhoneBook   phoneBook;

    (void)argv;
    if (argc != 1)
        return (1);
    std::cout << "Try one of these options:" << std::endl;
    std::cout << "\tADD\tSEARCH\t   EXIT" << std::endl;
    return (0);
}