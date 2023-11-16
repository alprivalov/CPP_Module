#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie{
	public:
		// constructor/destructor
		Zombie(void);
		void name_zombie(std::string name);
		~Zombie(void);
		
		//  getter
		void announce(void);
	private:
		std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif