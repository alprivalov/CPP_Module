#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
    std::cout << "Dog Default constructor called " << std::endl;
    return ;
}

Dog::Dog(std::string type): Animal(type)
{
    std::cout << "Dog Constructor parametric called " << std::endl;
    return ;
}

Dog::Dog(Dog const & src): Animal(src)
{
    std::cout << "Dog constructor called " << std::endl;
    *this = src;
    return ;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called " << std::endl;
    return ;
}

Dog & Dog::operator=(Dog const & rhs){
    std::cout << "Dog assignment operator called " << std::endl;
    this->_type = rhs._type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "woof" << std::endl;
}
