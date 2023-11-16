#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog("Dog");
    const Animal* cat = new Cat("Cat");
    const WrongAnimal* Wrong_meta = new WrongAnimal();
    const WrongAnimal* Wrong_i = new WrongCat("WrongCat");


    std::cout << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << Wrong_i->getType() << " " << std::endl;

    std::cout << std::endl;
    std::cout <<"Cat sound : ";
    cat->makeSound(); //will output the cat sound!
    std::cout <<"Dog sound : ";
    dog->makeSound();
    std::cout <<"Animal sound : ";
    meta->makeSound();

    std::cout << std::endl;
    std::cout <<"Wrong cat sound : ";
    Wrong_i->makeSound(); //will output the cat sound!
    std::cout <<"wrong Animal sound : ";
    Wrong_meta->makeSound();

    std::cout << std::endl;
    delete meta;
    delete cat;
    delete dog;
    delete Wrong_meta;
    delete Wrong_i;
    return 0;
}