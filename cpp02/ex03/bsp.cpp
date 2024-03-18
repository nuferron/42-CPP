#include "bsp.h"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point ab(b.getX() - a.getX(), b.getY() - a.getY());
	Point ac(c.getX() - a.getX(), c.getY() - a.getY());
	Point ap(point.getX() - a.getX(), point.getY() - a.getY());

	Fixed ct1((point.getX() - a.getX() - (ap.getY() * ab.getX() / ab.getY().toFloat())) / ac.getX().toFloat() - (ac.getY() / ab.getY()));
	Fixed ct2((point.getX() - a.getX() - ct1 * ac.getX()) / ab.getY().toFloat());

	std::cout << "ct1 " << ct1 << " ct2 " << ct2 << std::endl;

	if (ct1 > 0 && ct2 > 0 && ct1 + ct2 < 1)
		return (true);
	return (false);
}
/*
int main()
{
	Point	a(2, 2);
	Point	b(4, 6);
	Point	c(7, 2);
	Point	r(5.99f, 2.02f);
	
	float	area = a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());

	if (area == 0)
	{
		std::cerr << "Invalid triangle" << std::endl;
		return (1);
	}
	int i = bsp(a, b, c, r);
	if (i == true)
		std::cout << "Inside!!" << std::endl;
	else
		std::cout << "Out" << std::endl;
}*/
