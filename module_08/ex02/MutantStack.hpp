#include <stack>
#include <iostream>
#include <vector>
#include <list>
template<typename T>
class MutantStack :public std::stack<T>
{
private:
public:
    MutantStack(): std::stack<T>(){
        std::cout << "default constuctor called" << std::endl;
    }
    MutantStack(MutantStack const & src): std::stack<T>(0){
        std::cout << "Copy constuctor called" << std::endl;
        *this = src;
    }
    MutantStack operator=(MutantStack const & src){
        std::cout << "operator = called" << std::endl;
        (void)src;
        return(*this);
    }

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin(){
        return(this->c.begin());
    }

    iterator end(){
        return(this->c.end());
    }

    ~MutantStack(){
        std::cout << "destructor called" << std::endl;
    }
};
