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
		void	complain(const void *ptr);
    private:
        void        _debug();
        void        _info();
        void        _warning();
        void        _error();
        std::string _code[4];
        void    (Harl::*_call[4])();
};

#endif
