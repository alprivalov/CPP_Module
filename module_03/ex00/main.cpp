#include "ClapTrap.hpp"

int main(){
    {
    ClapTrap coco("coco",10,10,0);
    std::cout << std::endl;
    std::cout << "Claptrap " << coco.get_name() << " : " << std::endl;
    coco.attack("target");
    coco.beRepaired(50);
    coco.takeDamage(50);
    coco.takeDamage(50);
    coco.beRepaired(50);
    coco.takeDamage(50);
    coco.beRepaired(50);
    coco.takeDamage(50);
    coco.beRepaired(50);
    coco.takeDamage(50);
    std::cout << std::endl;
    }
}