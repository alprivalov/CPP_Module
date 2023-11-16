#include <string.h>
#include <iostream>

#ifndef HUMAN_HPP
#define HUMAN_HPP

class Weapon
{
private:
	std::string _type;
public:
	Weapon(std::string type);
	~Weapon();

	std::string &getType();
	void setType(std::string str);
};



#endif