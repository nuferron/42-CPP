#include "Fixed.hpp"

int main( void ) {
	Fixed a(5);
	Fixed b(10);

std::cout << a << std::endl;
std::cout << --a << std::endl;
std::cout << a << std::endl;
std::cout << a-- << std::endl;
std::cout << a << std::endl;
std::cout << Fixed::min(5, b) << std::endl;
std::cout << Fixed::max(a, b) << std::endl;

//	Fixed b(7);
//	std::cout << "pre A: " << a << std::endl;
//	std::cout << "++a " << ++a << std::endl;
//	std::cout << "post " << a << std::endl;
//	std::cout << "pre B: " << b << std::endl;
//	std::cout << "b++ " << b++ << std::endl;
//	std::cout << "post " << b << std::endl;
	return 0;
}
