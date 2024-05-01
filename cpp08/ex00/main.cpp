#include "easyfind.h"
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

template <typename T> void    test(T &var, int num)
{
    if (easyfind(var, num))
        std::cout << "An occurrence of " << num << " has been found" << std::endl;
    else
        std::cout << num << " not found" << std::endl;
}

int main()
{
    std::array<int, 6> arr{1, 2, 3, 4, 5, 6};
    std::vector<int> vec({1, 2, 3, 5, 7, 11});
    std::deque<int> deq({0, 2, 4, 6, 8, 10});
    std::list<int>  lst({-1, -2, -3, -4, -5});
    std::forward_list<int>  fwlst({-1, -2, -3, -5, -7, -11});
    
    test(arr, 4);
    test(vec, 9);
    test(deq, -1);
    test(lst, -1);
    test(fwlst, 13);
}