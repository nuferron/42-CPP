#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include "Serializer.h"

class Serializer
{
    public:
        static uintptr_t    serialize(Data *ptr);
        static Data         *deserialize(uintptr_t raw);
    private:
        Serializer();
        ~Serializer();
        Serializer(Serializer &s);
        Serializer  &operator=(const Serializer &s);
};

#endif