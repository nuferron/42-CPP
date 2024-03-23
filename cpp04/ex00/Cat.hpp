#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class   Cat: virtual public Animal
{
    public:
        Cat();
        Cat(const Cat &c);
        ~Cat();
        Cat     &operator=(const Cat &c);
        void    makeSound(void) const;
    private:
        const std::string _type;
};

#endif