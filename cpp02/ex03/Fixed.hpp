#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed
{
    public:
                Fixed();
                Fixed(const int n);
                Fixed(const float fl);
                Fixed(const Fixed &f);
                ~Fixed();
        Fixed   &operator=(const Fixed &f);
        bool	operator>(const Fixed &f) const;
        bool	operator>(float fl) const;
	bool	operator<(const Fixed &f) const;
        bool	operator<(float fl) const;
	bool	operator<=(const Fixed &f) const;
	bool	operator>=(const Fixed &f) const;
	bool	operator==(const Fixed &f) const;
	bool	operator!=(const Fixed &f) const;
	float	operator+(const Fixed &f) const;
	float	operator+(const float n) const;
	float	operator-(const Fixed &f) const;
	float	operator-(const float n) const;
	float	operator*(const Fixed &f) const;
	float	operator*(const float n) const;
	float	operator/(const Fixed &f) const;
	float	operator/(const float n) const;
	Fixed	operator++(void);
	Fixed	operator++(int);
	Fixed	operator--(void);
	Fixed	operator--(int);
	static Fixed	min(Fixed const &f1, Fixed const &f2);
	static Fixed	max(Fixed const &f1, Fixed const &f2);
	static Fixed	min(Fixed &f1, Fixed &f2);
	static Fixed	max(Fixed &f1, Fixed &f2);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
	float	toFloat(void) const;
	int	toInt(void) const;
    private:
        int             	_rawbits;
        static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif
