#include "easyfind.h"
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

template <typename T, typename C>
void    test(T &var, C find)
{
    if (easyfind(var, find))
        std::cout << "An occurrence of " << find << " has been found" << std::endl;
    else
        std::cout << find << " not found" << std::endl;
}

template <typename T, typename C>
void	init_type(T &var, C *val, int size, C find)
{
	var.assign(val, val + size);
	test(var, find);
}

/*int main()
{
	int val[] = {1, 2, 3, 5, 7, 11};
	std::vector<int> vec(val, val + sizeof(val) / sizeof(int));
	std::deque<int> deq(val, val + sizeof(val) / sizeof(int));
	std::list<int> lst(val, val + sizeof(val) / sizeof(int));
	
	test(vec, 5);
	test(deq, -1);
	test(lst, 0);
}*/

int main()
{
	int val[] = {1, 2, 3, 5, 7, 11};
	std::vector<int> vec;
	std::deque<int> deq;
	std::list<int> lst;

	init_type(vec, val, sizeof(val) / sizeof(int), 15);
	init_type(deq, val, sizeof(val) / sizeof(int), 7);
	init_type(lst, val, sizeof(val) / sizeof(int), 3);
}
