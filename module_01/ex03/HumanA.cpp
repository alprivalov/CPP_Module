#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& type) :
	_name(name),_weapon(type)
{
    std::cout << " Constructor parametric called HumanA " << std::endl;
}

HumanA::~HumanA()
{
    std::cout << " Destructor called HumanA " << std::endl;
}