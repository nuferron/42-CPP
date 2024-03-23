#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class   Cat: virtual public Animal, public Brain
{
    public:
        Cat();
        Cat(const Cat &c);
        ~Cat();
        Cat         &operator=(const Cat &c);
        std::string getType(void) const;
        void        makeSound(void) const;
    private:
        const std::string _type;
        Brain   *_brain;
};

#endif