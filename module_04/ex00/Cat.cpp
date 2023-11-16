#include "Cat.hpp"

Cat::Cat(void) :Animal("Cat")
{
    std::cout << "Cat Default constructor called " << std::endl;
    return ;
}

Cat::Cat(std::string type): Animal(type)
{
    std::cout << "Cat Constructor parametric called " << std::endl;
    return ;
}

Cat::Cat(Cat const & src): Animal(src)
{
    std::cout << "Cat Copy constructor called " << std::endl;
    *this = src;
    return ;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called " << std::endl;
    return ;
}

Cat & Cat::operator=(Cat const & rhs){
    std::cout << "Cat Copy assignment operator called " << std::endl;
    this->_type = rhs._type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "meow" << std::endl;
}
