#include "Serializer.hpp"

Serializer::Serializer(void)
{
    std::cout << "Serializer Default constructor called" << std::endl;
    return ;
}

Serializer::Serializer(Serializer const & src)
{
    std::cout << "Serializer Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Serializer::~Serializer()
{
    std::cout << "Serializer Destructor called" << std::endl;
    return ;
}

Serializer & Serializer::operator=(Serializer const & rhs){
    std::cout << " Copy assignment operator called Serializer" << std::endl;
    (void)rhs;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw){
    return (reinterpret_cast<Data*>(raw));
}
