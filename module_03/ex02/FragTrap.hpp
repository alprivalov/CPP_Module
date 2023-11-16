#include "ClapTrap.hpp"
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

class FragTrap : public ClapTrap
{
private:
public:
    //format canonique
    FragTrap(void);
    FragTrap & operator=(FragTrap const & rhs);
    FragTrap(FragTrap const & src);
    ~FragTrap();
    
    //additional constructor
    FragTrap(std::string name ,int hit_point ,int energy_point, int attack_damage);

    //functions
    void attack(const std::string& target);
    void highFivesGuys(void);
};


#endif