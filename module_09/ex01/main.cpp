#include "RPN.hpp"
#include <stdlib.h>



int main(int ac, char **av){
    RPN     rpn;

    if(ac != 2)
    {
        std::cout << "Error" << std::endl;
        return(1);
    }
    try
    {
        rpn.init_stack(av);
        rpn.print_stack();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return (0);
}