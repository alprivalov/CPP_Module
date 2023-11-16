#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << &str << "L'adresse de la string en mémoire" << std::endl;
	std::cout << stringPTR << "L'adresse stockée dans stringPTR" << std::endl;
	std::cout << &stringREF  << "L'adresse stockée dans stringREF" << std::endl;
	std::cout << str << "La valeur de la string" << std::endl;
	std::cout << *stringPTR <<"La valeur pointée par stringPTR" << std::endl;
	std::cout << stringREF <<"La valeur pointée par stringREF" << std::endl;
}