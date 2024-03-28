#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Cat cat;

    std::cout << "Creating cat2" << std::endl << std::endl;

    Cat cat2(cat);
    //Dog dog;

    //cat.makeSound();
    //cat2.printIdeas();
    //dog.makeSound();

    cat.~Cat();

    std::cout << "Deleting cat2" << std::endl << std::endl;
}