#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap a("robot");
	DiamondTrap b;
	b.attack("robot");
	a.takeDamage(b.getAttack());
	a.attack("Frankenstein");
	b.takeDamage(a.getAttack());
	a.beRepaired(5);
	a.attack("Frankenstein");
	b.takeDamage(a.getAttack());
	a.attack("Frankenstein");
	b.takeDamage(a.getAttack());
	a.attack("Frankenstein");
	b.whoAmI();
	a.whoAmI();
    return (0);
}
