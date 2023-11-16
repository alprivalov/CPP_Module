#include "RPN.hpp"

RPN::RPN(void)
{
    // std::cout << "RPN Default constructor called" << std::endl;
    return ;
}

RPN::RPN(RPN const & src)
{
    // std::cout << "RPN Copy constructor called" << std::endl;
    *this = src;
    return ;
}

RPN::~RPN()
{
    // std::cout << "RPN Destructor called" << std::endl;
    return ;
}

RPN & RPN::operator=(RPN const & rhs){
    // std::cout << " Copy assignment operator called RPN" << std::endl;
    if(this != &rhs)
        stack = rhs.stack;
    return *this;
}


std::ostream & operator<< (std::ostream & o, RPN const & rhs){
    (void)rhs;
    return o;
}

const char* RPN::WrongArgumentException::what() const throw(){
    return("Error");
}

void    RPN::init_stack(char **av){
    std::string first_argument_input;

    parsing(first_argument_input.append(av[1]));
}

void    RPN::parsing(std::string str){
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*' && str[i] != ' '){
            if(str[i] < '0' || str[i] > '9')
                throw WrongArgumentException();
            stack.push(int(str[i]) - 48);
            if(i + 1 < str.size() && str[i + 1] != ' ')
                throw WrongArgumentException();
            continue;
        }
        else if(str[i] != ' '){
            if(stack.size() < 2)
                throw WrongArgumentException();
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            if (str[i] == '+')
                stack.push(a + b);
            else if (str[i] == '-')
                stack.push(a - b);
            else if (str[i] == '*')
                stack.push(a * b);
            else if (b != 0)
                stack.push(a / b);
            else
                throw WrongArgumentException();
        }
    }
}

void    RPN::print_stack(){
    std::stack<int> stack_tmp;
    int number_element_in_stack = stack.size();
    for(int i = 0; i < number_element_in_stack;i++)
    {
        std::cout << stack.top() << std::endl;
        stack_tmp.push(stack.top());
        stack.pop();
    }
    for(int i = 0; i < number_element_in_stack;i++)
    {
        stack.push(stack_tmp.top());
        stack_tmp.pop();
    }
}
