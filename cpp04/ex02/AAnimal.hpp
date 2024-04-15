#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class   AAnimal
{
    public:
        AAnimal();
        AAnimal(const std::string str);
        AAnimal(const AAnimal &a);
        virtual ~AAnimal();
        AAnimal			&operator=(const AAnimal &a);
        virtual void	makeSound(void) const = 0;
    private:
        std::string _type;
};

#endif
