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
    WrongCat(std::string type);
    WrongCat(WrongCat const & src);
    WrongCat & operator=(WrongCat const & rhs);
    ~WrongCat();
    
    //getter
	void makeSound() const;
    std::string getType() const;
};

#endif