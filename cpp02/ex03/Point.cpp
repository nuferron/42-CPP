#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const Fixed &fx, const Fixed &fy): _x(fx), _y(fy) {}

Point::Point(float x, float y): _x(x), _y(y) {}

Point::Point(const Point &p): _x(p._x), _y(p._y) {}

Point::~Point() {}

Point	&Point::operator=(const Point &p)
{
	(void)p;
	return (*this);
}

const Fixed	&Point::getX(void) const
{
	return (_x);
}

const Fixed	&Point::getY(void) const
{
	return (this->_y);
}

Point	Point::operator-(const Point &p) const
{
	Point r(this->getX() - p.getX(), this->getY() - p.getY());
	return (r);
}
