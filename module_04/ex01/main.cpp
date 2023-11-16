#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <cstdio>
#include <stdlib.h>

int main()
{
    Dog dog1(Cat("cat"));

    // srand(time(NULL));
    // {
    //     std::cout << "Mandatory :" << std::endl;

    //     Dog *dog1 = new Dog();
    //     Dog *dog2 = new Dog();
    //     Cat *cat1 = new Cat();
    //     Cat *cat2 = new Cat();

    //     std::cout << std::endl;
    //     std::cout << "dog2 :" << "Get ideas :" <<std::endl;
    //     dog2->getter_ideas();
    //     std::cout << std::endl << "dog1 :" << "Get ideas :" <<std::endl;
    //     dog1->getter_ideas();
    //     std::cout << std::endl << "cat2 :" << "Get ideas :" <<std::endl;
    //     cat2->getter_ideas();
    //     std::cout << std::endl << "cat1 :" << "Get ideas :" <<std::endl;
    //     cat1->getter_ideas();
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    //     delete dog2;
    //     delete dog1;
    //     delete cat1;
    //     delete cat2;
    // }
    //     std::cout << std::endl;
    // {
    //     std::cout << "Deep copy :" << std::endl;
    //     Animal z[4];
    //     Dog *dog1 = new Dog();
    //     Dog *dog2 = new Dog();

    //     z[0] = *dog1;
    //     z[1] = *dog2;
    //     std::cout << "dog 2 = dog 1: "<< std::endl;
    //     *dog2 = *dog1;
    //     std::cout << std::endl;
    //     std::cout << "dog 2 deleted: "<< std::endl;
    //     delete dog1;
    //     std::cout << std::endl;
    //     std::cout << "Get ideas :" <<std::endl;
    //     dog2->getter_ideas();
    //     std::cout << std::endl;

    //     std::cout << std::endl;
    //     delete dog2;
    // }
    // return 0;
    // }
}