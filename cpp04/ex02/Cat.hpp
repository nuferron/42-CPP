#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Cat: virtual public Animal
{
    public:
        Cat();
        Cat(Cat &c);
        ~Cat();
        Cat         &operator=(Cat &c);
        std::string getType(void) const;
        void        setIdea(const std::string &str) const;
        void        makeSound(void) const;
        void        printIdeas(void) const;
    private:
        const std::string _type;
        Brain   *_brain;
};

#endif