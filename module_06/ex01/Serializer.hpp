#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>
#include "Data.hpp"
#include <string>
#include <stdint.h>

class Serializer
{
protected:
public:
    //format canonique
    Serializer(Serializer const & src);
    Serializer & operator=(Serializer const & rhs);
    ~Serializer();

    //additional constructor
   
    //getter

    //functions
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
private:
    Serializer(void);
};

#endif