#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a;
	ClapTrap b("pepe");

	a.setAttack(4);
	b.setAttack(4);
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	b.takeDamage(a.getAttack());
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.attack(a.getName());
	a.takeDamage(b.getAttack());
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	b.takeDamage(a.getAttack());
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
    return (0);
}
