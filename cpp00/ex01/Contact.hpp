#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
    public:
        Contact() = default;
        ~Contact() = default;
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone;
        std::string secret;
}

#endif