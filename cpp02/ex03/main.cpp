#include "bsp.h"

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
}
