#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a;
	ClapTrap b("pepe");

	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	b.beRepaired(10);
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
    return (0);
}
