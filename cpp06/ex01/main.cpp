#include "Serializer.hpp"

int main()
{
    Data        data;
    uintptr_t   uptr;
    Data        *ptr;

    data.c = 'b';
    data.num = 42;
    std::cout << "INITIAL DATA: num = " << data.num
                << " c = " << data.c << std::endl;
    uptr = Serializer::serialize(&data);
	std::cout << "uptr: " << uptr << std::endl;
    ptr = Serializer::deserialize(uptr);
    std::cout << "FINAL DATA: num = " << ptr->num
                << " c = " << ptr->c << std::endl;
}
