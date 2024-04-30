#include "whatever.h"

void    itest(int a, int b)
{
    std::cout << "PRE a: " << a << " b: " << b << std::endl;
    swap<int>(a, b);
    std::cout << "POST a: " << a << " b: " << b << std::endl;
    std::cout << "MIN " << min<int>(a, b) << std::endl;
    std::cout << "MAX " << max<int>(a, b) << std::endl;
}

void    ftest(float a, float b)
{
    std::cout << "PRE a: " << a << " b: " << b << std::endl;
    swap<float>(a, b);
    std::cout << "POST a: " << a << " b: " << b << std::endl;
    std::cout << "MIN " << min<float>(a, b) << std::endl;
    std::cout << "MAX " << max<float>(a, b) << std::endl;
}

void    ctest(char a, char b)
{
    std::cout << "PRE a: " << a << " b: " << b << std::endl;
    swap<char>(a, b);
    std::cout << "POST a: " << a << " b: " << b << std::endl;
    std::cout << "MIN " << min<char>(a, b) << std::endl;
    std::cout << "MAX " << max<char>(a, b) << std::endl;
}

int main()
{
    itest(3, 5);
    std::cout << std::endl;
    ftest(1.2f, 5.5f);
    std::cout << std::endl;
    ctest('a', 'A');
}

/*int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return (0);
}*/