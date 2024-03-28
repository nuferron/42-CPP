#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class   Animal
{
    public:
        Animal();
        Animal(const std::string str);
        Animal(const Animal &a);
        virtual ~Animal();
        Animal      &operator=(const Animal &a);
        virtual void        makeSound(void) const = 0;
    private:
        std::string _type;
};

#endif