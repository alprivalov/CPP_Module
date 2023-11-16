#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdio>
#include <stdlib.h> 

Base * generate(void){
    int n = rand() % 3;
    switch (n)
    {
    case 1:
       return(new A);
        break;
    case 2:
       return(new B);
        break;
    }
    return(new C);
}

void identify(Base* p){
    if(dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    if(dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    if(dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
}

void identify(Base& p){
    try
    {
        if(dynamic_cast<C *>(&p))
            std::cout << "C" << std::endl;
        if(dynamic_cast<B *>(&p))
            std::cout << "B" << std::endl;
        if(dynamic_cast<A *>(&p))
            std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

// void identify(Base* p)
int main(){
    Base *test;
    
    srand(time(NULL));
    test = generate();
    identify(test);
    delete test;
    test = generate();
    identify(test);
    delete test;
}

// identify(Base& p)
// int main(){
//     Base *test_failed;
    
//     srand(time(NULL));
//     identify(*test_failed);
// }
