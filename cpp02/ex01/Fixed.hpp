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
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
		float	toFloat(void) const;
    private:
        int             	_rawbits;
        static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif
