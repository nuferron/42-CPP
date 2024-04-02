#include "Character.hpp"

Character::Character(): _total(0), _name("Hans")
{
    for (int i = 0; i < 4; i++)
        this->_slots[i] = NULL;
}

Character::Character(const std::string &name): _total(0), _name(name)
{
    for (int i = 0; i < 4; i++)
        this->_slots[i] = NULL;
}

Character::Character(Character &c): _total(c._total), _name(c._name)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_slots[i])
            delete this->_slots[i];
        if (c._slots[i])
            this->_slots[i] = c._slots[i]->clone();
        else
            this->_slots[i] = NULL;
    }
}

Character::~Character()
{
    /*for (int i = 0; i < 4; i++)
    {
        if (this->_slots[i])
            delete this->_slots[i];
    }*/
}

Character &Character::operator=(const Character &c)
{
    this->_total = c._total;
    this->_name = c._name;
    for (int i = 0; i < 4; i++)
    {
        if (this->_slots[i])
            delete this->_slots[i];
        if (c._slots[i])
            this->_slots[i] = c._slots[i]->clone();
        else
            this->_slots[i] = NULL;
    }
    return (*this);
}

std::string const   &Character::getName(void) const
{
    return (this->_name);
}

void    Character::equip(AMateria *m)
{
    int empty = -1;

    if (this->_total == 4)
    {
        std::cout << "Full inventory!" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (empty == -1 && !this->_slots[i])
            empty = i;
        else if (this->_slots[i] == m)
        {
            std::cout << "This " << m->getType() << " is already equiped!" << std::endl;
            return ;
        }
    }
    this->_slots[empty] = m;
    std::cout << m->getType() << " has been equiped in slot " << empty << std::endl;
    this->_total++;
}

void    Character::unequip(int idx)
{
    if (this->_total == 0)
    {
        std:: cout << "Inventory is already empty!" << std::endl;
        return ;
    }
    if (!this->_slots[idx])
    {
        std::cout << "Slot " << idx << " is already empty!" << std::endl;
        return ;
    }
    std::cout << this->_slots[idx]->getType() << " has been unequipped" << std::endl;
    this->_slots[idx] = NULL;
    this->_total--;
}

void    Character::use(int idx, ICharacter &target)
{
    if (!this->_slots[idx])
    {
        std::cout << "Slot " << idx << " is empty!" << std::endl;
        return ;
    }
    std::cout << this->_name;
    this->_slots[idx]->use(target);
}