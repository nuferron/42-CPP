#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "D.hpp"
#include <stdlib.h>

Base    *generate(void)
{
    srand(time(0));
    switch (rand() % 3 + 1)
    {
        case 1:
        {
            std::cout << "Generate A" << std::endl;
            return (new A);
        }
        case 2:
        {
            std::cout << "Generate B" << std::endl;
            return (new B);
        }
        case 3:
        {
            std::cout << "Generate C" << std::endl;
            return (new C);
        }
    }
    return (NULL);
}

void    identify(Base *ptr)
{
    Base    *type;

    type = dynamic_cast<A *>(ptr);
    if (type)
    {
        std::cout << "Ptr identification: type A" << std::endl;
        return ;
    }
    type = dynamic_cast<B *>(ptr);
    if (type)
    {
        std::cout << "Ptr identification: type B" << std::endl;
        return ;
    }
    type = dynamic_cast<C *>(ptr);
    if (type)
    {
        std::cout << "Ptr identification: type C" << std::endl;
        return ;
    }
    std::cerr << "Ptr identification: unknown type" << std::endl;
}

void    identify(Base &ref)
{
    Base    type;

    std::cout << "Ref identification: ";
    try
    {
        type = dynamic_cast<A&>(ref);
        std::cout << "type A" << std::endl;
        return ;
    }
    catch (std::exception &ex) {}
    try
    {
        type = dynamic_cast<B&>(ref);
        std::cout << "type B" << std::endl;
        return ;
    }
    catch (std::exception &ex) {}
    try
    {
        type = dynamic_cast<C&>(ref);
        std::cout << "type C" << std::endl;
        return ;
    }
    catch (std::exception &ex)
    {
        std::cerr << "unknown type" << std::endl;
    }
    
}

int main()
{
    Base    *base;

    base = generate();
    identify(base);
    identify(*base);
    delete base;

    std::cout << std::endl << "TEST WITH UNKNOWN TYPE" << std::endl;
    D   d;

    identify(&d);
    identify(d);
}