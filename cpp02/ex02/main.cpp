#include "Fixed.hpp"
/*
int main( void ) {
	Fixed a(5);
	Fixed b(10);

	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << "min(5, b) b being 10: " << Fixed::min(5, b) << std::endl;
	std::cout << "max(a, b) a being 5 and b being 10: " << Fixed::max(a, b) << std::endl;

	Fixed c(7);
	std::cout << "pre A: " << a << std::endl;
	std::cout << "++a " << ++a << std::endl;
	std::cout << "post " << a << std::endl;
	std::cout << "pre C: " << c << std::endl;
	std::cout << "c++ " << c++ << std::endl;
	std::cout << "post " << c << std::endl;
	return 0;
}
*/
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
