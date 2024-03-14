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
	Fixed d(c);
	std::cout << "A -> " << a.getRawBits() << std::endl;
	std::cout << "C -> " << c.getRawBits() << std::endl;
	std::cout << "D -> " << d.getRawBits() << std::endl;
    return (0);
}
