#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

/*int main()
{
    Animal a;
    Dog dog;
    Cat cat;
    std::cout << "a " + a.getType() << std::endl;
    std::cout << "cat " + cat.getType() << std::endl;
    std::cout << "dog " + dog.getType() << std::endl;
    cat.makeSound();
    dog.makeSound();
}*/

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    dog->makeSound(); //will output the cat sound!
    cat->makeSound();
    animal->makeSound();

    delete animal;
    delete dog;
    delete cat;

    std::cout << std::endl << "What if it was wrong?" << std::endl << std::endl;

    const WrongAnimal* wronganimal = new WrongAnimal();
    const WrongAnimal* wrongcat = new WrongCat();
    std::cout << wrongcat->getType() << " " << std::endl;
    wrongcat->makeSound();
    wronganimal->makeSound();

    delete wronganimal;
    delete wrongcat;
}