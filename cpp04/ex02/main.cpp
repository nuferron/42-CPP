#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Cat cat;
	Cat	cat1(cat);
	Dog dog;
	
	std::cout << std::endl << "CAT" << std::endl;
	cat.makeSound();
	cat.setIdea("I'm hungry");
	cat.printIdeas();
	
	std::cout << std::endl << "CAT1" << std::endl;
	cat1.makeSound();
	cat1.printIdeas();
	
	std::cout << std::endl << "CAT2" << std::endl;
	Cat cat2(cat);
	cat2.printIdeas();
	
	std::cout << std::endl << "DOG" << std::endl;
	dog.makeSound();
	dog.printIdeas();
	std::cout << std::endl;
	return (0);
}

/*int main() // Does NOT compile (it shouldn't)
{
	AAnimal animal;

	(void)animal;
}*/
