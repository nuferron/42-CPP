#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptr = &str;
    std::string &ref = str;

    std::cout << "str MEMORY ADDRESS" << &str << std::endl;
    std::cout << "memory address HELD by ptr" << ptr << std::endl;
    std::cout << "memory address HELD by ref" << ref << std::endl;
}