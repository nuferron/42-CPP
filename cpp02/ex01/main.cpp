#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;


	/**** SOME MORE TESTS ****/
	a.setRawBits(5);
	c = a;
	Fixed d(3.14f);
	std::cout << "A -> " << a << std::endl;
	std::cout << "C -> " << c << std::endl;
	std::cout << "D -> " << d << std::endl;
    return (0);
}
