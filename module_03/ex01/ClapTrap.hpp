#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string _name;
    int _hit_point;
    int _energy_point;
    int _attack_damage;
public:
    //format canonique
    ClapTrap(void);
    ClapTrap & operator=(ClapTrap const & rhs);
    ClapTrap(ClapTrap const & src);
    ~ClapTrap();

    //additional constructor
    ClapTrap(std::string name ,int hit_point ,int energy_point, int attack_damage);

    //getter
    std::string get_name() const;
    int get_energy_point() const;
    int get_attack_damage() const;

    //functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif