#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

/*int main()
{
	Ice *ice = new Ice();
	Cure *cure = new Cure();
	Character player;
	Character player2("bob");

	player.equip(ice);
	player.use(0, player2);
	player.unequip(0);
	player.equip(cure);
	player.use(0, player2);
	player.unequip(0);
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
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}
/*
int main()
{
	Character	*me = new Character("me");
	Character	*other = new Character("other");
	Ice			*ice = new Ice();

	me->equip(ice);
	me->use(0, *other);
	other->use(0, *me);
	*other = *me;
	other->use(0, *me);

	delete me;
	delete other;
}*/
