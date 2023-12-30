#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class   PhoneBook
{
    public:
                PhoneBook();
                ~PhoneBook();
        Contact agenda[8];
        int     add_contact();
        void    preview_agenda();
        int     get_total();
    private:
        int total;
		int	id;
};

#endif
