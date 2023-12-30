#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "Agenda.h"

class Contact
{
    public:
                Contact();
                ~Contact();
        int     new_contact();
        void    print_preview();
        void    print_contact();
    private:
        void    print(std::string arg);
        int     set_contact_vars(std::string &str);
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone;
        std::string secret;
};

#endif
