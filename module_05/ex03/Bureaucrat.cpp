#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):_name("Roger")
{
    _grade = 75;
    std::cout << "Bureaucrat Default constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    if(_grade > 150)
        throw GradeTooLowException();
    if(_grade <= 0)
        throw GradeTooHighException();
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
    return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs){
    if(this != &rhs)
        _grade = rhs._grade;
    return *this;
}


std::ostream & operator<< (std::ostream & o, Bureaucrat const & rhs){
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return("Grade too Low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return("Grade too high");
}

void    Bureaucrat::increment_grade(){
    if(_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrement_grade(){
    if(_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

std::string Bureaucrat::getName() const{
    return (_name);
}

int Bureaucrat::getGrade() const{
    return (_grade);
}

void Bureaucrat::signForm(AForm &form){
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form){
    try
    {
        form.execute(*this);
        std::cout << *this << " executed " << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << *this <<  " couldn't execute PresidentialPardonForm because " <<  e.what() << std::endl;
    }
}