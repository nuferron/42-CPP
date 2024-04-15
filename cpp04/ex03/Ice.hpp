#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class   Ice: virtual public AMateria
{
    public:
        Ice();
        Ice(Ice &i);
        ~Ice();
        Ice &operator=(Ice &i);
        Ice *clone() const;
        void    use(ICharacter &target);
};

#endif
