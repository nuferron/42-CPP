#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(Ice &i): AMateria(i.getType()) {}

Ice::~Ice() {}

Ice &Ice::operator=(Ice &i)
{
    (void)i;
    return (*this);
}

Ice *Ice::clone() const
{
    return (new Ice());
}

void    Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName()  << " *"<< std::endl;
}
