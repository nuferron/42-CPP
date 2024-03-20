#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("robot");
	ScavTrap b;
	b.attack("robot");
	a.takeDamage(b.getAttack());
	a.attack("pepe");
	b.takeDamage(a.getAttack());
	a.beRepaired(5);
	a.attack("pepe");
	b.takeDamage(a.getAttack());
	a.attack("pepe");
	b.takeDamage(a.getAttack());
	a.attack("pepe");
	b.takeDamage(a.getAttack());
	a.attack("pepe");
	b.takeDamage(a.getAttack());
	a.attack("pepe");
	b.takeDamage(a.getAttack());
	a.attack("pepe");
	b.takeDamage(a.getAttack());
    return (0);
}
