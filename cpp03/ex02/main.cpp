#include "FragTrap.hpp"

int main(void)
{
	FragTrap a("robot");
	FragTrap b;
	b.attack("robot");
	a.takeDamage(b.getAttack());
	a.attack("Wall-E");
	b.takeDamage(a.getAttack());
	a.beRepaired(5);
	a.attack("Wall-E");
	b.takeDamage(a.getAttack());
	a.attack("Wall-E");
	b.takeDamage(a.getAttack());
	a.attack("Wall-E");
	b.highFivesGuys();
    return (0);
}
