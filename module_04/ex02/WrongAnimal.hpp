#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
private:

protected:
    std::string _type;
public:
    //format canonique
    WrongAnimal(void);
    WrongAnimal(std::string type);
    WrongAnimal(WrongAnimal const & src);
    WrongAnimal & operator=(WrongAnimal const & rhs);
    virtual ~WrongAnimal();
    
    //getter
	void makeSound() const;
    std::string getType() const;
};

#endif