#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "Agenda.h"

class Contact
{
    public:
                Contact();
                ~Contact();
        void    new_contact();
        void    full_print();
        void    partial_print();
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone;
        std::string secret;
};

#endif