#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "Agenda.h"

class Contact
{
    public:
                Contact();
                ~Contact();
        void    new_contact();
        void    print_var();
    private:
        void    print(std::string arg);
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone;
        std::string secret;
};

#endif