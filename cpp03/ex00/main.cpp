#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a;
	ClapTrap b("pepe");

	a.attack(b.getName());
	b.beRepaired(1);
    return (0);
}
