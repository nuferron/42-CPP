#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class   PHONEBOOK_HPP
{
    public:
        PhoneBook() = default;
        ~PhoneBook() = default;
        Contact agenda[8];
    private:
        int id;
}

#endif