#include "PmergeMe.hpp"

#include <stdlib.h>
#include <iostream>
int main(int ac, char **av){
    PmergeMe instance;
    if(ac < 2)
    {
        std::cerr << "Error : Wrong number of argument" << std::endl;
        return(1);
    }
    try
    {
        instance.init_vector(ac, av);
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
