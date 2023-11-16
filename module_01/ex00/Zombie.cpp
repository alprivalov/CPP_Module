#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	_name = name;
	std::cout << _name << " Constructor parametric called Zombie " << std::endl;
	return;
}

Zombie::Zombie(void){
	_name = "Charle";
	std::cout << _name << " Default constructor called Zombie " << std::endl;
	return;
}

Zombie::~Zombie(void){
	std::cout << this->_name << " Destructor called Zombie " << std::endl;
	return;
}

void Zombie::announce(void){
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ... " << std::endl;
}