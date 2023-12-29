#include "Zombie.h"

int main()
{
    Zombie  *saved_zombie;
    std::string heap_name;
    std::string stack_name;
    
    std::cout << YELLOW << "Insert a name for the zombie saved in the heap memory" << RESET << std::endl;
    getline(std::cin, heap_name);
    std::cout << YELLOW << "Insert a name for the zombie saved in the stack memory" << RESET << std::endl;
    getline(std::cin, stack_name);
    std::cout << std::endl;
    if (heap_name == "")
        heap_name = "HEAP";
    if (stack_name == "")
        stack_name = "STACK";
    saved_zombie = new_zombie(heap_name);
    randomChump(stack_name);
    saved_zombie->announce();
    delete saved_zombie;
    return (0);
}