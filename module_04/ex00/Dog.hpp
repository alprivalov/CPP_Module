#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
protected:

private:

public:
    //format canonique
    Dog(void);
    Dog(std::string type);
    Dog & operator=(Dog const & rhs);
    Dog(Dog const & src);
    ~Dog();
    
    //getter
    //functions

    void makeSound() const;
};
#endif