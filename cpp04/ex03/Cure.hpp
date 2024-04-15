#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class   Cure: virtual public AMateria
{
    public:
        Cure();
        Cure(Cure &i);
        ~Cure();
        Cure &operator=(Cure &i);
        Cure *clone() const;
        void    use(ICharacter &target);
};

#endif
