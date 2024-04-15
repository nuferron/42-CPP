#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal* dog;
    Animal* cat;
    Dog* dog1 = new Dog();
    Cat* cat1 = new Cat();
    
    std::cout << dog1->getType() << std::endl;
    std::cout << cat1->getType() << std::endl;

    std::cout << std::endl;
    cat1->setIdea("sleep");
    cat1->setIdea("eat");
    cat1->setIdea("scratch");
    cat1->printIdeas();

    std::cout << std::endl;
    dog1->setIdea("play");
    dog1->setIdea("pee");
    dog1->setIdea("sleep");
    dog1->printIdeas();
    std::cout << std::endl;

    cat = cat1;
    dog = dog1;
    cat->makeSound();
    dog->makeSound();

    delete dog;
    delete cat;
}
/*
int main ()
{
	Cat	*cat1 = new Cat();
	Cat	*cat2 = new Cat();

    std::cout << std::endl;
    cat1->printIdeas();
    cat1->setIdea("sleep");
    cat1->setIdea("eat");
    cat1->setIdea("scratch");
    cat1->printIdeas();

    std::cout << "EQUAL"<< std::endl;
	*cat2 = *cat1;
    cat2->setIdea("go berserk");
    cat2->printIdeas();
    std::cout << std::endl;
	
	delete cat1;
	delete cat2;
}*/
