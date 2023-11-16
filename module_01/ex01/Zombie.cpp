#include "Zombie.hpp"

Zombie::Zombie(void){
	std::cout << _name << "Default Constructor called Zombie " << std::endl;
}

Zombie::~Zombie(void){
	std::cout << this->_name << " Destructor called Zombie " << std::endl;
	return;
}

void Zombie::name_zombie(std::string name){
	_name = name;
}

void Zombie::announce(void){
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ... " << std::endl;
}