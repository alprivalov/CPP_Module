#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
    this->_hit_point = 100;
    this->_energy_point = 50;
    this->_attack_damage = 20;
    std::cout << this->_name << " ScavTrap Default constructor called" << std::endl;
    return;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs){
    ClapTrap::_name = rhs.get_name();
    ClapTrap::_energy_point = rhs.get_energy_point();
    ClapTrap::_attack_damage = rhs.get_attack_damage();
    return *this;
}

ScavTrap::ScavTrap(std::string name ,int hit_point ,int energy_point, int attack_damage): ClapTrap(name, hit_point, energy_point, attack_damage)
{
    this->_hit_point = 100;
    this->_energy_point = 50;
    this->_attack_damage = 20;
    std::cout << _name << " ScavTrap Copy assignment operator called " << std::endl;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap(src)
{
    std::cout << this->_name << " ScavTrap Copy constructor called " << std::endl;
    *this = src;
    return ;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->_name << " ScavTrap Destructor called " << std::endl;
    return ;
}

void ScavTrap::guardGate(){
    std::cout << _name << " ScavTrap est entré en mode Gate keeper" << std::endl;
}

void ScavTrap::attack(const std::string& target){

    if((_hit_point) <= 0)
        std::cout <<  "ScavTrap " << this->_name << " is dead " << std::endl;
    else if(_energy_point <= 0)
        std::cout <<  "ScavTrap " << this->_name << " no energy left " << std::endl;
    else
    {
        std::cout <<  "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_point--;
    }
}