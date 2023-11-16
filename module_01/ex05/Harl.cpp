#include "Harl.hpp"

Harl::Harl(){
	std::cout << "Default constructor called Harl " << std::endl;
}

Harl::~Harl(){
	std::cout << "Destructor called Harl " << std::endl;
}

void Harl::debug( void ){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info( void ){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;

}

void Harl::warning( void ){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;

}

void Harl::error( void ){
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;

}
typedef struct s_test{
	std::string test;
	void	(Harl::*f)();
}t_test;

void Harl::complain( std::string level ){
	t_test test[4] = {
		{"DEBUG",&Harl::debug},
		{"INFO",&Harl::info},
		{"WARNING",&Harl::warning},
		{"ERROR",&Harl::error},
	};
	for(int i = 0; i < 4;i++)
	{
		if (!level.compare(test[i].test))
			(this->*(test[i].f))();
	}
}