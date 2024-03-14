#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _rawbits = 0;
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(f.getRawBits());
	return (*this);
}

ostream &operator>>(ostream &out, const Fixed &f)
{}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawbits);
}
void	Fixed::setRawBits(int const raw)
{
	this->_rawbits = raw;	
}
