#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern Default constructor called" << std::endl;
    return ;
}

Intern::Intern(Intern const & src)
{
    std::cout << "Intern Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called" << std::endl;
    return ;
}

Intern & Intern::operator=(Intern const & rhs){
    std::cout << " Copy assignment operator called Intern" << std::endl;
    (void)rhs;
    return *this;
}

AForm * Intern::makeForm(std::string form_str, std::string target){
    int n = 4;
    AForm *form = NULL;
    std::string str[3] = {
        "RobotomyRequestForm",
        "ShrubberyCreationForm",
        "PresidentialPardonForm",
    };
    for(int i = 0; i < 3; i++)
    {
        if(!str[i].compare(form_str))
            n = i;
    }
    switch (n)
    {
    case 0:
        form = new RobotomyRequestForm(target);
        std::cout << "Intern creates " << *form << std::endl;
        break;
    case 1:
        form = new ShrubberyCreationForm(target);
        std::cout << "Intern creates " << *form << std::endl;
        break;
    case 2:
        form = new PresidentialPardonForm(target);
        std::cout << "Intern creates " << *form << std::endl;
        break;
    default : 
        throw CannotCreateFormException();
        break;
    }
    return(form);
}

const char* Intern::CannotCreateFormException::what() const throw(){
    return("Cannot Create Form");
}
