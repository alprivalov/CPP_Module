#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>

class RPN 
{
private:
    std::stack<int> stack;
    void             parsing(std::string str);
    class WrongArgumentException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
protected:
public:
    //format canonique
    RPN(void);
    RPN(RPN const & src);
    RPN & operator=(RPN const & rhs);
    ~RPN();

    //additional constructor
   
    //getter
    
    //functions

    void    print_stack();
    void    init_stack(char **av);
};
std::ostream & operator<<(std::ostream & o, RPN const & rhs);

#endif