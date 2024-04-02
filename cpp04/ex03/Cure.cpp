#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(Cure &c): AMateria(c.getType()) {}

Cure::~Cure() {}

Cure &Cure::operator=(Cure &c)
{
    (void)c;
    return (*this);
}

Cure *Cure::clone() const
{
    Cure *copy = new Cure();

    return (copy);
}

void    Cure::use(ICharacter &target)
{
    std::cout << " heals " << target.getName() << "'s wounds" << std::endl;
}