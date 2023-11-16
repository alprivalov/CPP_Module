#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
public:
    //format canonique
    ScavTrap(void);
    ScavTrap & operator=(ScavTrap const & rhs);
    ScavTrap(ScavTrap const & src);
    ~ScavTrap();

    //additional constructor
    ScavTrap(std::string name ,int hit_point ,int energy_point, int attack_damage);
    //functions
    void guardGate();
    void attack(const std::string& target);
};


#endif