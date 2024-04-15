#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class   Dog: virtual public AAnimal
{
    public:
        Dog();
        Dog(Dog &d);
        ~Dog();
        Dog         &operator=(Dog &d);
        std::string getType(void) const;
        void        setIdea(const std::string &str);
        void        makeSound(void) const;
        void        printIdeas(void) const;
    private:
        const std::string _type;
        Brain   *_brain;
};

#endif
