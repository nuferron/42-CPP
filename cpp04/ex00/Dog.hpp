#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class   Dog: virtual public Animal
{
    public:
        Dog();
        Dog(const Dog &d);
        ~Dog();
        Dog     &operator=(const Dog &d);
        void    makeSound(void) const;
    private:
        const std::string _type;
};

#endif