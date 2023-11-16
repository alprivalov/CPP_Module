#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie{
	public:
		// constructor/destructor
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
		//  getter
		void announce(void);
	private:
		std::string _name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);
#endif