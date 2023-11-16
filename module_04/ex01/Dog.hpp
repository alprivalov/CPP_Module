#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{

private:
    Brain *brain;
protected:

public:
    //format canonique
    Dog(void);
    Dog(std::string type);
    Dog & operator=(Dog const & rhs);
    Dog(Dog const & src);
    ~Dog();
    
    //getter
    void    getter_ideas() const;
    //functions
    void    makeSound() const;
};
#endif