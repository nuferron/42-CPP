#include "Fixed.hpp"

Fixed::Fixed()
{
    _rawbits = 0;
}

Fixed::Fixed(const Fixed &f)
{
    *this = f;
}

Fixed::Fixed(const int n)
{
	this->setRawBits(n << _bits);
}

Fixed::Fixed(const float fl)
{
	this->setRawBits(roundf(fl * (1 << _bits)));
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(Fixed const &f)
{
	this->setRawBits(f.getRawBits());
	return (*this);
}

bool	Fixed::operator>(Fixed const &f) const
{
	return (this->_rawbits > f.getRawBits());
}

bool	Fixed::operator<(Fixed const &f) const
{
	return (this->_rawbits < f.getRawBits());
}

bool	Fixed::operator>=(Fixed const &f) const
{
	return (this->_rawbits >= f.getRawBits());
}

bool	Fixed::operator<=(Fixed const &f) const
{
	return (this->_rawbits <= f.getRawBits());
}

bool	Fixed::operator==(Fixed const &f) const
{
	return (this->_rawbits == f.getRawBits());
}

bool	Fixed::operator!=(Fixed const &f) const
{
	return (this->_rawbits != f.getRawBits());
}

float	Fixed::operator+(Fixed const &f) const
{
	return (this->toFloat() + f.toFloat());
}

float	Fixed::operator+(float n) const
{
	return (this->toFloat() + n);
}

float	Fixed::operator-(Fixed const &f) const
{
	return (this->toFloat() - f.toFloat());
}

float	Fixed::operator-(float n) const
{
	return (this->toFloat() - n);
}

float	Fixed::operator*(Fixed const &f) const
{
	return (this->toFloat() * f.toFloat());
}

float	Fixed::operator*(float n) const
{
	return (this->toFloat() * n);
}

float	Fixed::operator/(Fixed const &f) const
{
	return (this->toFloat() / f.toFloat());
}

float	Fixed::operator/(float n) const
{
	return (this->toFloat() / n);
}

//a++
Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->_rawbits += 1;
	return (tmp);
}

//++a
Fixed	Fixed::operator++(void)
{
	this->_rawbits += 1;
	return(*this);
}

//a--
Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->_rawbits -= 1;
	return (tmp);
}

//--a
Fixed	Fixed::operator--(void)
{
	this->_rawbits -= 1;
	return(*this);
}

Fixed	Fixed::min(Fixed const &f1, Fixed const &f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}

Fixed	Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}

Fixed	Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (f1 < f2)
		return (f2);
	return (f1);
}

Fixed	Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f2);
	return (f1);
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
