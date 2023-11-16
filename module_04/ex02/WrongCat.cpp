#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
    std::cout << "WrongCat Default constructor called " << std::endl;
    return ;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type)
{
    std::cout << "WrongCat Copy assignment operator called " << std::endl;
    return ;
}

WrongCat::WrongCat(WrongCat const & src): WrongAnimal(src)
{
    std::cout << "WrongCat Copy constructor called " << std::endl;
    *this = src;
    return ;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called " << std::endl;
    return ;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs){
    _type = rhs._type;
    return *this;
}

std::string WrongCat::getType() const
{
	return this->_type;
}

void WrongCat::makeSound() const
{
	std::cout << "Default Wrong Cat sound" << std::endl;
}
