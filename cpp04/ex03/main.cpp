#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

/*int main()
{
    Ice ice;
    Cure cure;
    Cure cure2;
    Ice ice2;
    Ice ice3;
    Character player;
    Character player2("Saturos");

    std::cout << ice.getType() << std::endl;
    std::cout << cure.getType() << std::endl;
    std::cout << player.getName() << std::endl;

    player.equip(&ice);
    player.equip(&ice);
    player.equip(&ice2);
    player.equip(&ice3);
    player.equip(&cure);
    player.equip(&cure2);
    player.unequip(2);
    player.unequip(2);
    player.equip(&cure);
    player.use(1, player2);
}*/

/*int main()
{
	Ice *ice = new Ice();
	Character player;
	Character player2("bob");

	player.equip(ice);
	player.use(0, player2);
    std::cout << ice->getType() << std::endl;
    std::cout << player.getName() << std::endl;
}*/

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	return (0);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}
