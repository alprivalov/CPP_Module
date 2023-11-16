#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm",25,5)
{
    _target = "Default";
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string executor): AForm("PresidentialPardonForm",25,5)
{
    _target = executor;
    std::cout << "PresidentialPardonForm parametric constructor called" << std::endl;
    return ;
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): AForm(src)
{
    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
    *this = src;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
    return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs){
    if(this != &rhs)
    {
        _target = rhs._target;
    }
    std::cout << " Copy assignment operator called PresidentialPardonForm" << std::endl;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)const{
    AForm::execute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}