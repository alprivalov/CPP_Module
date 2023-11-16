#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal Default constructor called " << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
    std::cout << "WrongAnimal Constructor parametric called " << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    std::cout << "WrongAnimal Copy constructor called " << std::endl;
    *this = src;
    return ;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called " << std::endl;
    return ;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs){
    std::cout << "WrongAnimal Copy assignment operator called " << std::endl;
    _type = rhs._type;
    return *this;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Default Wrong Animal sound" << std::endl;
}
