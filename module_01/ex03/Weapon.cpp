#include "Weapon.hpp"

Weapon::Weapon(std::string type) :
	_type(type)
{
    std::cout << " Constructor parametric called s " << std::endl;
}

Weapon::~Weapon()
{
    std::cout << " Destructor called Weapon " << std::endl;
}

std::string &Weapon::getType()
{
	return(_type);
}

void Weapon::setType(std::string str)
{
	_type = str;
}
