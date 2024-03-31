#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Cat cat;

    std::cout << "Creating cat2" << std::endl << std::endl;

    Cat cat2(cat);
    Dog dog;

    cat.makeSound();
    cat.setIdea("hello");
    cat.printIdeas();

    std::cout << std::endl << std::endl;
    cat2.printIdeas();
    dog.makeSound();
    dog.printIdeas();
}