#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

protected:

public:
    //format canonique
    WrongCat(void);
    WrongCat(WrongCat const & src);
    WrongCat & operator=(WrongCat const & rhs);
    ~WrongCat();
    
    //additional constructor
    WrongCat(std::string type);
    //getter
	void makeSound() const;
    std::string getType() const;
};

#endif