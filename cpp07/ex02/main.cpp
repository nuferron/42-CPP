#include "Array.hpp"

template <typename T>void    print(const char *s, Array<T> &a)
{
    std::cout << s;
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

void    itest(void)
{
    Array <int>arr;
    Array <int>arr2(3);

    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = i;
    arr = arr2;
    print("ARR: ", arr);
    print("ARR2: ", arr2);
    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = i * 2;
    print("ARR: ", arr);
    print("ARR2: ", arr2);
}

void    ftest(void)
{
    Array <float>arr;
    Array <float>arr2(5);

    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = i * 13 / 10;
    arr = arr2;
    print("ARR: ", arr);
    print("ARR2: ", arr2);
    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = i * 2;
    print("ARR: ", arr);
    print("ARR2: ", arr2);
}

int main()
{
    try {
        std::cout << "ITEST" << std::endl;
        itest();
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        std::cout << "FTEST" << std::endl;
        ftest();
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        std::cout << "ITEST" << std::endl;
        itest();
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << std::endl;
    return (0);
}