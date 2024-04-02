#ifndef MATERIA_CPP
# define MATERIA_CPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        const std::string _type;
    public:
        AMateria(); //default constructor
        AMateria(AMateria &m); //copy constructor
        AMateria(std::string const & type);
        virtual ~AMateria();
        AMateria &operator=(AMateria &m); //Copy assignment operator
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif