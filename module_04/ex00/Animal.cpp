#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal Default constructor called" << std::endl;
    return ;
}

Animal::Animal(std::string type): _type(type)
{
    std::cout << "Animal Constructor parametric called" << std::endl;
    return ;
}

Animal::Animal(Animal const & src)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
    return ;
}

Animal & Animal::operator=(Animal const & rhs){
    std::cout << "Animal Copy assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::makeSound() const
{
	std::cout << "Default animal sound" << std::endl;
}
