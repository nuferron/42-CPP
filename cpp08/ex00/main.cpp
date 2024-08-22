#include "easyfind.h"
#include <vector>
#include <deque>
#include <list>
#include <iostream>

template <typename T, typename C>
void    test(T &var, C find)
{
    if (easyfind(var, find))
        std::cout << "An occurrence of " << find << " has been found" << std::endl;
    else
        std::cout << find << " was not found" << std::endl;
}

int main()
{
	int val[] = {1, 2, 3, 5, 7, 11};
	std::vector<int> vec(val, val + sizeof(val) / sizeof(int));
	std::deque<int> deq(val, val + sizeof(val) / sizeof(int));
	std::list<int> lst(val, val + sizeof(val) / sizeof(int));
	
	test(vec, 15);
	test(deq, 7);
	test(lst, 3);
}
