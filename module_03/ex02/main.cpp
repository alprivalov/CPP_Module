#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main(){
    {
    ClapTrap coco("coco",10,10,0);
    std::cout << std::endl;
    std::cout << "Claptrap " << coco.get_name() << " : " << std::endl;
    coco.attack("target");
    coco.beRepaired(50);
    coco.takeDamage(50);
    std::cout << std::endl;
    }
    std::cout << std::endl;
    {
    ScavTrap salut("salut",100,50,20);
    std::cout << std::endl;
    std::cout << "Scavtrap " << salut.get_name() << " : " << std::endl;
    salut.attack("target");
    salut.beRepaired(50);
    salut.takeDamage(50);
    salut.guardGate();
    std::cout << std::endl;
    }
    std::cout << std::endl;
    {
    FragTrap aurevoir("aurevoir",100,100,30);
    std::cout << std::endl;
    std::cout << "FragTrap " << aurevoir.get_name() << " : " << std::endl;
    aurevoir.attack("target");
    aurevoir.beRepaired(50);
    aurevoir.takeDamage(50);
    aurevoir.highFivesGuys();
    std::cout << std::endl;
    }
}