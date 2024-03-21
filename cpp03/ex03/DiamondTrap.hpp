#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &d);
		~DiamondTrap();
		DiamondTrap	&operator=(const DiamondTrap &d);
		void		whoAmI(void) const;
	private:
		std::string	_name;
};

#endif
