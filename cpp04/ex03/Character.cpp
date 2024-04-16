#include "Character.hpp"

Character::Character(): _total(0), _name("Hans")
{
	this->_discarded = NULL;
    for (int i = 0; i < 4; i++)
        this->_slots[i] = NULL;
}

Character::Character(const std::string &name): _total(0), _name(name)
{
	this->_discarded = NULL;
    for (int i = 0; i < 4; i++)
        this->_slots[i] = NULL;
}

Character::Character(Character &c): _total(c._total), _name(c._name)
{
	this->_discarded = NULL;
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
    for (int i = 0; i < 4; i++)
    {
        if (this->_slots[i])
            delete this->_slots[i];
    }
	if (this->_discarded)
	{
		for (int i = 0; this->_discarded[i]; i++)
			delete this->_discarded[i];
		delete [] this->_discarded;
	}
}

Character &Character::operator=(const Character &c)
{
    this->_total = c._total;
    this->_name = c._name;
	if (this->_discarded)
	{
		for (int i = 0; this->_discarded[i]; i++)
			delete this->_discarded[i];
		delete [] this->_discarded;
	}
	this->_discarded = NULL;
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

	if (!m)
	{
		std::cout << "Nothing to equip!" << std::endl;
		return ;
	}
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
    //std::cout << m->getType() << " has been equiped in slot " << empty << std::endl;
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
	this->_discarded = this->_toDiscardPile(this->_slots[idx]);
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
    this->_slots[idx]->use(target);
}

AMateria	**Character::_toDiscardPile(AMateria *m)
{
	int total = 0;
	AMateria **newpile;

	if (this->_discarded)
	{	
		while (this->_discarded[total])
			total++;
	}
	newpile = new AMateria*[total + 2];
	for (int i = 0; i < total; i++)
		newpile[i] = this->_discarded[i];
	newpile[total] = m;
	newpile[total + 1] = NULL;
	delete [] this->_discarded;
	return (newpile);
}
