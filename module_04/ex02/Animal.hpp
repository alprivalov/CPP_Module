#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
private:

protected:
    std::string _type;
public:
    //format canonique
    Animal(void);
    Animal(std::string type);
    Animal(Animal const & src);
    Animal & operator=(Animal const & rhs);
    virtual ~Animal();
    
    //getter
    virtual void getter_ideas() const;
    std::string getType() const;

	//functions
	virtual void makeSound() const = 0;
};

#endif