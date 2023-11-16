#include "HumanB.hpp"

void	HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
	_weapon = &weapon;
}

HumanB::HumanB(std::string name) :
	_name(name)
{
    std::cout << " Constructor parametric called HumanB " << std::endl;
}

HumanB::~HumanB()
{
    std::cout << " Destructor called HumanB " << std::endl;
}