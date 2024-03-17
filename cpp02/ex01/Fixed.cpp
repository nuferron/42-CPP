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
	this->setRawBits(n << _bits);
}

Fixed::Fixed(const float fl)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(fl * (1 << _bits)));
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

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}

int	Fixed::getRawBits(void) const
{
	return (_rawbits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawbits = raw;	
}

float	Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (1 << _bits));
}

int	Fixed::toInt(void) const
{
	return (_rawbits >> _bits);
}
