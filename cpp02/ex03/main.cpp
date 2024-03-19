#include "Point.hpp"

int main()
{
	Point	a(2, 2);
	Point	b(4, 6);
	Point	c(7, 2);
	Point	r(4, 3);
	
	float	area = a.getX() * (b.getY() - c.getY())
				+ b.getX() * (c.getY() - a.getY())
				+ c.getX() * (a.getY() - b.getY());

	if (area == 0)
		return (std::cerr << "Error: Invalid triangle" << std::endl, 1);
	std::cout << "The point " << r << " ";
	if (bsp(a, b, c, r) ==  true)
		std::cout << "belongs to the triangle"<< std::endl;
	else
		std::cout << "doesn't belong to the triangle" << std::endl;
	return (0);
}
