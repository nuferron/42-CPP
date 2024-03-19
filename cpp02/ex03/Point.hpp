#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	public:
		Point();
		Point(const Fixed &x, const Fixed &y);
		Point(float x, float y);
		Point(const Point &p);
		~Point();
		Point &operator=(const Point &p);
		Point operator-(const Point &p) const;
		const Fixed	&getX(void) const;
		const Fixed	&getY(void) const;
	private:
		const Fixed _x;
		const Fixed _y;
};

std::ostream	&operator<<(std::ostream &out, const Point &p);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
