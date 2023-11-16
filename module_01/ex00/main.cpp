#include <iostream>
#include "Zombie.hpp"

int main()
{	
	Zombie *zombie = newZombie("salut");
	Zombie zombie1;

	randomChump("aurevoir");
	zombie1.announce();

	delete zombie;
	return (1);
}