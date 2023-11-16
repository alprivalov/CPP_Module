#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *brain;
protected:

public:
    //format canonique
    Cat(void);
    Cat(std::string type);
    Cat & operator=(Cat const & rhs);
    Cat(Cat const & src);
    ~Cat();
    //getter
    void    getter_ideas() const;
    //functions
    void makeSound() const;
};

#endif