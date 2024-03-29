#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed
{
    public:
                Fixed();
                Fixed(const Fixed &f);
                ~Fixed();
        Fixed   &operator=(const Fixed &f);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
    private:
        int             	_rawbits;
        static const int	_bits = 8;
};

#endif
