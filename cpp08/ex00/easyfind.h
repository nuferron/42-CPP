#ifndef EASYFIND_H
# define EASYFIND_H

#include <algorithm>

template <typename T>
bool easyfind(T &var, int num)
{
	if (std::find(var.begin(), var.end(), num) != var.end())
		return (true);
	return (false);
}

#endif
