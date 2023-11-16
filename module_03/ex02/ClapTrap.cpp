#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_name("Pierre"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
    this->_hit_point = 10;
    this->_energy_point = 10;
    this->_attack_damage = 0;
    std::cout << this->_name << " ClapTrap Default constructor called " << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string name ,int hit_point ,int energy_point, int attack_damage): _name(name), _hit_point(hit_point), _energy_point(energy_point), _attack_damage(attack_damage)
{
    std::cout << "ClapTrap Constructor parametric called " << std::endl;
    this->_hit_point = 10;
    this->_energy_point = 10;
    this->_attack_damage = 0;
    return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << this->_name << " ClapTrap Copy constructor called " << std::endl;
    *this = src;
    return;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->_name << " ClapTrap Destructor called " << std::endl;
    return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs){
    std::cout << this->_name << " ClapTrap Copy assignment operator called " << std::endl;
    this->_name = rhs.get_name();
    this->_energy_point = rhs.get_energy_point();
    this->_attack_damage = rhs.get_attack_damage();
    return *this;
}

std::string ClapTrap::get_name() const {
    return (_name);
}

int ClapTrap::get_energy_point() const{
    return (_energy_point);
}

int ClapTrap::get_attack_damage() const{
    return (_attack_damage);
}

void ClapTrap::attack(const std::string& target){

    if((_hit_point) <= 0)
        std::cout <<  "ClapTrap " << this->_name << " is dead " << std::endl;
    else if(_energy_point <= 0)
        std::cout <<  "ClapTrap " << this->_name << " no energy left " << std::endl;
    else
    {
        std::cout <<  "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_point--;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if(_hit_point <= 0)
        std::cout <<  "ClapTrap " << this->_name << " is dead " << std::endl;
    else if(_energy_point <= 0)
        std::cout <<  "ClapTrap " << this->_name << " no energy left " << std::endl;
    else
    {
        std::cout <<  "ClapTrap " << this->_name << " take "  << amount << " damage " << std::endl;
        this->_hit_point -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if(_hit_point <= 0)
        std::cout <<  "ClapTrap " << this->_name << " cant heal he's dead " << std::endl;
    else if(_energy_point <= 0)
        std::cout <<  "ClapTrap " << this->_name << " no energy left " << std::endl;
    else
    {
        this->_energy_point--;
        this->_hit_point += amount;
        std::cout <<  "ClapTrap " << this->_name << " repaire " << amount << " hit_points " << std::endl;
    }
}
