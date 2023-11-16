#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
    brain = new Brain();
    std::cout << "Dog Default constructor called" << std::endl;
    return ;
}

Dog::Dog(std::string type): Animal(type)
{
    brain = new Brain();
    std::cout << "Dog assignment operator called" << std::endl;
    return ;
}

Dog::Dog(Dog const & src): Animal(src)
{
    std::cout << "Dog constructor called" << std::endl;
    brain = NULL;
    *this = src;
    return ;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called" << std::endl;
    return ;
}

Dog & Dog::operator=(Dog const & rhs){
    std::cout << "Operator copy constructor called" << std::endl;
    this->_type = rhs._type;
    if(this != &rhs)
    {
        if (brain)
            delete  brain;
        brain = new Brain();
        *this->brain = *rhs.brain;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "woof" << std::endl;
}


void    Dog::getter_ideas() const{
    brain->getter_ideas();
}