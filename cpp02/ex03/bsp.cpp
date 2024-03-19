#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point ab(b.getX() - a.getX(), b.getY() - a.getY());
	Point ac(c.getX() - a.getX(), c.getY() - a.getY());
	Point ap(point.getX() - a.getX(), point.getY() - a.getY());

	Fixed ct1((point.getX() - a.getX() - (ap.getY() * ab.getX() / ab.getY().toFloat()))
				/ ac.getX().toFloat() - (ac.getY() / ab.getY()));
	Fixed ct2((point.getX() - a.getX() - ct1 * ac.getX()) / ab.getY().toFloat());

	if (ct1 > 0 && ct2 > 0 && ct1 + ct2 < 1)
		return (true);
	return (false);
}
