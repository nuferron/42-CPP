#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"

class Character: virtual public ICharacter
{
    public:
        Character();
        Character(const std::string &name);
        Character(Character &c);
        ~Character();
        Character &operator=(const Character &c);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
    private:
        AMateria    *_slots[4];
        int         _total;
        std::string _name;
};

#endif
