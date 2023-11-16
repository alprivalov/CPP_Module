#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <cstdio>
#include <stdlib.h> 


//class abstraite correct
int main()
{
    srand(time(NULL));
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << std::endl << "dog :" << "Get ideas :" <<std::endl;
    dog->getter_ideas();
    std::cout << std::endl << "cat :" << "Get ideas :" <<std::endl;
    cat->getter_ideas();
    std::cout << std::endl;
    std::cout << std::endl;
    delete dog;
    delete cat;
    return 0;
}

// class abstraite erreur
// int main()
// {
    // srand(time(NULL));
//     const Animal* dog = new Animal();
//     const Animal* cat = new Animal();
//     std::cout << std::endl << "dog :" << "Get ideas :" <<std::endl;
//     dog->getter_ideas();
//     std::cout << std::endl << "cat :" << "Get ideas :" <<std::endl;
//     cat->getter_ideas();
//     std::cout << std::endl;
//     std::cout << std::endl;
//     delete dog;
//     delete cat;
//     return 0;
// }  