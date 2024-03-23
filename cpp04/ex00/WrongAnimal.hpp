#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class   WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const std::string str);
        WrongAnimal(const WrongAnimal &a);
        virtual ~WrongAnimal();
        WrongAnimal      &operator=(const WrongAnimal &a);
        std::string getType(void) const;
        virtual void        makeSound(void) const;
    private:
        std::string _type;
};

#endif