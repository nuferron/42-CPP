#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    Ice ice;
    Cure cure;
    Cure cure2;
    Ice ice2;
    Ice ice3;
    Character player;
    Character player2("Saturos");

    std::cout << ice.getType() << std::endl;
    std::cout << cure.getType() << std::endl;
    std::cout << player.getName() << std::endl;

    player.equip(&ice);
    player.equip(&ice);
    player.equip(&ice2);
    player.equip(&ice3);
    player.equip(&cure);
    player.equip(&cure2);
    player.unequip(2);
    player.unequip(2);
    player.equip(&cure);
    player.use(1, player2);


}