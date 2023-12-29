#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "str's MEMORY ADDRESS:\t\t  " << &str << std::endl;
    std::cout << "memory address HELD by stringPTR: " << stringPTR << std::endl;
    std::cout << "memory address HELD by stringREF: " << &stringREF << std::endl;

    std::cout << "str CONTENT: " << str << std::endl;
    std::cout << "ptr CONTENT: " << *stringPTR << std::endl;
    std::cout << "ref CONTENT: " << stringREF << std::endl;
}