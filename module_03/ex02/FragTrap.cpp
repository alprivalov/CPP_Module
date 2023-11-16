#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
    this->_hit_point = 100;
    this->_energy_point = 100;
    this->_attack_damage = 30;
    std::cout << this->_name << "FragTrap Default constructor called " << std::endl;
    return;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs){
    std::cout << _name << " FragTrap Copy assignment operator called " << std::endl;
    ClapTrap::_name = rhs.get_name();
    ClapTrap::_energy_point = rhs.get_energy_point();
    ClapTrap::_attack_damage = rhs.get_attack_damage();
    return *this;
}

FragTrap::FragTrap(std::string name ,int hit_point ,int energy_point, int attack_damage): ClapTrap(name, hit_point, energy_point, attack_damage)
{
    std::cout << "FragTrap Constructor parametric called" << std::endl;
    this->_hit_point = 100;
    this->_energy_point = 100;
    this->_attack_damage = 30;
    return ;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap(src)
{
    std::cout << this->_name << " FragTrap Copy constructor called " << std::endl;
    *this = src;
    return ;
}

FragTrap::~FragTrap()
{
    std::cout << this->_name << " FragTrap Destructor called " << std::endl;
    return ;
}

void FragTrap::attack(const std::string& target){

    if((_hit_point) <= 0)
        std::cout <<  "FragTrap " << this->_name << " is dead " << std::endl;
    else if(_energy_point <= 0)
        std::cout <<  "FragTrap " << this->_name << " no energy left " << std::endl;
    else
    {
        std::cout <<  "FragTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_point--;
    }
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->_name << " would like to high five everyone!" << std::endl;
}