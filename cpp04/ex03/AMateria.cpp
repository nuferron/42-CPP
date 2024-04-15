#include "AMateria.hpp"

AMateria::AMateria(): _type("none") {}

AMateria::AMateria(AMateria &m): _type(m._type) {}

AMateria::AMateria(std::string const &type): _type(type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(AMateria &m)
{
    (void)m;
    return (*this);
}

const std::string &AMateria::getType(void) const
{
    return (this->_type);
}

void    AMateria::use(ICharacter &target)
{
    (void)target;
}
