#include "Cat.hpp"

Cat::Cat(void) :Animal("Cat")
{
    brain = new Brain();
    std::cout << "Cat Default constructor called" << std::endl;
    return ;
}

Cat::Cat(std::string type): Animal(type)
{
    brain = new Brain();
    std::cout << "Cat Copy assignment operator called" << std::endl;
    return ;
}

Cat::Cat(Cat const & src): Animal(src)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    brain = NULL;
    *this = src;
    return ;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor called" << std::endl;
    return ;
}

Cat & Cat::operator=(Cat const & rhs){
    std::cout << "Operator copy constructor called" << std::endl;
    this->_type = rhs._type;
    if(brain)
        delete  this->brain;
    brain = new Brain();
    this->brain = rhs.brain;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "meow" << std::endl;
}

void    Cat::getter_ideas() const{
    brain->getter_ideas();
}