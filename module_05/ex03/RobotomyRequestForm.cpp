#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm",72,45)
{
    _target = "Default";
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string executor): AForm("RobotomyRequestForm",72,45)
{
    _target = executor;
    std::cout << "RobotomyRequestForm parametric constructor called" << std::endl;
    return ;
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): AForm(src)
{
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
    *this = src;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
    return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs){
    if(this != &rhs)
    {
        _target = rhs._target;
    }
    std::cout << " Copy assignment operator called RobotomyRequestForm" << std::endl;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)const{
    std::cout << "Makes some drilling noises." << std::endl;

    try
    {
        AForm::execute(executor);
        int n = rand() % 2;
        if(n == 1)
            std::cout << _target <<  "has been robotomized successfully 50% of the time."<< std::endl;
    }
    catch(std::exception & e)
    {
        std::cout << *this << " robotomy failed. because" << e.what() << std::endl;
    }
}