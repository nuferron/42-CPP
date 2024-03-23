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
        virtual std::string getType(void) const;
        virtual void        makeSound(void) const;
    private:
        std::string _type;
};

#endif