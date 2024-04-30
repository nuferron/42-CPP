#include "iter.h"

void    itest(void)
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13};

    iter(arr, 7, &add_one);
    std::cout << "new arr: ";
    for (int i = 0; i < 7; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void    ftest(void)
{
    float arr[] = {1.1f, 3.3f, 5.5f, 7.7f, 9.9f, 11.11f, 13.13f};

    iter(arr, 7, &add_one);
    std::cout << "new arr: ";
    for (int i = 0; i < 7; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void    ctest(void)
{
    char arr[] = {'a', 'c', 'e', 'g', 'i', 'k', 'm'};

    iter(arr, 7, &add_one);
    std::cout << "new arr: ";
    for (int i = 0; i < 7; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    itest();
    ftest();
    ctest();
}