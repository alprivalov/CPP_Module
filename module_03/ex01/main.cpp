#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    {
    ClapTrap coco("coco",100,100,30);
    std::cout << std::endl;
    std::cout << "Claptrap " << coco.get_name() << " : " << std::endl;
    coco.attack("target");
    coco.beRepaired(50);
    coco.takeDamage(50);
    coco.attack("aurevoir");
    coco.beRepaired(145);
    coco.takeDamage(100);
    coco.takeDamage(40);
    coco.attack("Bibi");
    coco.takeDamage(40);
    coco.takeDamage(40);
    std::cout << std::endl;
    }
    std::cout << std::endl;
    {
    ScavTrap salut("bonjour",10,30,10);
    std::cout << std::endl;
    std::cout << "Scavtrap " << salut.get_name() << " : " << std::endl;
    salut.attack("target");
    salut.guardGate();
    salut.beRepaired(50);
    salut.takeDamage(50);
    salut.guardGate();
    std::cout << std::endl;
    }
}