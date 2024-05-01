#include "Array.hpp"

int main()
{
    Array <int>arr();
    Array <int>arr2(3);

    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = i;
    std::cout << "PRE:" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    arr = arr2;
    std::cout << "POST:" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}