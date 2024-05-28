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
    Array <int>arr2(5);

    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = i;
    arr = arr2;
    print("ARR: ", arr);
    print("ARR2: ", arr2);
    for (unsigned int i = 0; i < 7; i++)
        arr2[i] = i * 2;
    print("ARR: ", arr);
    print("ARR2: ", arr2);
}

void    ftest(void)
{
    Array <float>arr;
    Array <float>arr2(5);

    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = (float)i * 13 / 10;
    arr = arr2;
    print("ARR: ", arr);
    print("ARR2: ", arr2);
    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = i * 2;
    print("ARR: ", arr);
    print("ARR2: ", arr2);
}

void    ctest(void)
{
    Array <char>arr;
    Array <char>arr2(5);

    std::cout << "Printing NULL arr: " << arr[0] << std::endl;
    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = (char)(i + 65);
    arr = arr2;
    print("ARR: ", arr);
    print("ARR2: ", arr2);
    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = (char)(i + 97);
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
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        std::cout << "FTEST" << std::endl;
        ftest();
    }
    catch (std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        std::cout << "CTEST" << std::endl;
        ctest();
    }
    catch (std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    return (0);
}
