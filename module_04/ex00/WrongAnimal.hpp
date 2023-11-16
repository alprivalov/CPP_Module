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
    WrongAnimal(WrongAnimal const & src);
    WrongAnimal & operator=(WrongAnimal const & rhs);
    virtual ~WrongAnimal();
    
    //additional constructor
    WrongAnimal(std::string type);
    
    //getter
	void makeSound() const;
    std::string getType() const;
};

#endif