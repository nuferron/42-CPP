#include "Harl.hpp"

Harl::Harl()
{
    /*this->_code[0] = "DEBUG";
    this->_code[1] = "INFO";
    this->_code[2] = "WARNING";
    this->_code[3] = "ERROR";*/
}

Harl::~Harl() {}

void    Harl::_debug()
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "6 hours of debugging can save you 5 minutes of reading documentation" << std::endl;
}

void    Harl::_info()
{
    std::cout "I’ve been involved in a number of cults, both a leader and a follower. You have more fun as a follower, but you make more money as a leader." << std::endl;
}

void    Harl::_warning()
{
    std::cout << "So, have you tried turning it off and on again?" << std::endl;
}

void    Harl::_error()
{
    std::cout << "Everything is very bad. Good luck." << std::endl;
}

void    Harl::complain()
{}