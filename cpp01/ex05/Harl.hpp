#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class   Harl
{
    public:
                Harl();
                ~Harl();
        void    complain(std::string level);
    private:
        void        _debug();
        void        _info();
        void        _warning();
        void        _error();
        std::string _code[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
        
}

#endif