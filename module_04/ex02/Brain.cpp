#include "Brain.hpp"
#include <cstdio>
#include <stdlib.h> 

Brain::Brain(void)
{
    std::string ideas[5];

    ideas[0] = "Manger";
    ideas[1] = "Dormir";
    ideas[2] = "Chasser";
    ideas[3] = "Jouer";
    ideas[4] = "Boire";

    int n = rand() % 5;
    for(int i = 0; i < 100 ;i++)
    {
        this->ideas[i] = ideas[n];
        n = rand() % 5;
    }
    std::cout << "Brain Default constructor called" << std::endl;
    return ;
}

Brain::Brain(Brain const & src)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
    return ;
}

Brain & Brain::operator=(Brain const & rhs){
    if(this != &rhs)
    {
        for(int i = 0;i < 100;i++)
            ideas[i] = rhs.ideas[i];
    }
    return *this;
}

void    Brain::getter_ideas(){
    for(int i = 0;i < 100;i++)
        std::cout << ideas[i] << " ";
}