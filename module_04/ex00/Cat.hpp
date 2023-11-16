#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
private:

protected:

public:
    //format canonique
    Cat(void);
    Cat(std::string type);
    Cat & operator=(Cat const & rhs);
    Cat(Cat const & src);
    ~Cat();
    //getter
    //functions
    void makeSound() const;
};

#endif