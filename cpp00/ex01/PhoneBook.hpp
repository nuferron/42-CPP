#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class   PhoneBook
{
    public:
                PhoneBook();
                ~PhoneBook();
        Contact agenda[8];
        void    add_contact();
        void    view_agenda();
        void    preview_agenda();
    private:
        int id;
};

#endif