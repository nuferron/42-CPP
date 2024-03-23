#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class   WrongCat: virtual public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &c);
        ~WrongCat();
        WrongCat     &operator=(const WrongCat &c);
        void    makeSound(void) const;
    private:
        const std::string _type;
};

#endif