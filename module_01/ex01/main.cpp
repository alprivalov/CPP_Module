#include <iostream>
#include "Zombie.hpp"

int main()
{
	int nb_zombies;
	nb_zombies = 42;
	Zombie *horde = zombieHorde(nb_zombies, "salut");
	
	delete [] horde;
	return (1);
}