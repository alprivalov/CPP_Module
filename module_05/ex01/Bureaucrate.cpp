#include "Bureaucrate.hpp"

Bureaucrate::Bureaucrate(void):_name("Roger")
{
    _grade = 75;
    std::cout << "Bureaucrate Default constructor called" << std::endl;
    return ;
}

Bureaucrate::Bureaucrate(std::string name, int grade): _name(name), _grade(grade)
{
    if(_grade > 150)
        throw GradeTooLowException();
    if(_grade <= 0)
        throw GradeTooHighException();
    std::cout << "Bureaucrate Copy assignment operator called" << std::endl;
    return ;
}

Bureaucrate::Bureaucrate(Bureaucrate const & src)
{
    std::cout << "Bureaucrate Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Bureaucrate::~Bureaucrate()
{
    std::cout << "Bureaucrate Destructor called" << std::endl;
    return ;
}

Bureaucrate & Bureaucrate::operator=(Bureaucrate const & rhs){
    if(this != &rhs)
        _grade = rhs._grade;
    return *this;
}


std::ostream & operator<< (std::ostream & o, Bureaucrate const & rhs){
    o << rhs.getName() << ", bureaucrat grade" << rhs.getGrade();
    return o;
}

const char* Bureaucrate::GradeTooLowException::what() const throw(){
    return("error GradeTooLowException");
}

const char* Bureaucrate::GradeTooHighException::what() const throw(){
    return("error GradeTooHighException");
}

void    Bureaucrate::increment_grade(){
    if(_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void    Bureaucrate::decrement_grade(){
    if(_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

std::string Bureaucrate::getName() const{
    return (_name);
}

int Bureaucrate::getGrade() const{
    return (_grade);
}

void Bureaucrate::signForm(Form &form){
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
    }
}