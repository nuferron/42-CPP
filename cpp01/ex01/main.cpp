#include "Zombie.h"

static int get_name(std::string &name)
{
    std::cout << YELLOW << "Insert the name of the zombies from the horde" << RESET << std::endl;
    getline(std::cin, name);
    if (std::cin.eof())
        return (1);
    if (name == "")
        name = "HORDE";
    return (0);
}

int num_to_str(std::string str)
{
    int i = 0;
    int num = 0;
    int len = str.length() - 1;

    if (str == "")
        return (-1);
    while (str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
        i++;
    while (str[len] == '\t' || str[len] == '\v' || str[len] == ' ')
        len--;
    if (str[i] == '+')
        i++;
    if (i > len)
        return (-1);
    while (i <= len)
    {
        if (str[i] < '0' || str[i] > '9' || num < 0)
            return (-1);
        num = (str[i] - '0') + (num * 10);
        i++;
    }
    return (num);
}

static int  get_number()
{
    int n;
    std::string str;

    std::cout << YELLOW << "Insert the number of zombies in the horde" << RESET << std::endl;
    while (1)
    {
        getline(std::cin, str);
        if (std::cin.eof())
            return (-1);
        n = num_to_str(str);
        if (n < 0)
            std::cout << RED << "That's not a valid number for a horde... It must be a natural int" << RESET << std::endl;
        else
            break ;            
    }
    if (n < 5)
        std::cout << CYAN << "That's not what I'd call a horde, but whatever..." << RESET << std::endl;
    return (n);
}

int main()
{
    std::string name;
    Zombie      *horde;
    int         n;

    if (get_name(name))
        return (1);
    n = get_number();
    if (n < 0)
        return (1);
    horde = zombieHorde(n, name);
    for (int i = 0; i < n; i++)
        horde[i].announce();
    delete [] horde;
}