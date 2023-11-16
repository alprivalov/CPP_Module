#include "Form.hpp"

Form::Form(void): _grade_signed(75),_grade_execute(75)
{
    std::cout << "Form Default constructor called" << std::endl;
    return ;
}

Form::Form(std::string name, int grade_signed ,int grade_execute): name(name), _grade_signed(grade_signed),_grade_execute(grade_execute) 
{
    if(grade_signed < 0 || grade_execute < 0)
        throw GradeTooHighException();
    if(grade_signed > 150 || grade_execute > 150)
        throw GradeTooLowException();
    std::cout << "Form Copy assignment operator called" << std::endl;
    return ;
}

Form::Form(Form const & src): name(src.name),_grade_signed(src._grade_signed),_grade_execute(src._grade_execute)
{
    std::cout << "Form Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
    return ;
}

Form & Form::operator=(Form const & rhs){
    if(this != &rhs)
        _signed = rhs._signed;
    return *this;
}

std::string Form::getName()const{
    return (name);
}

std::ostream & operator<< (std::ostream & o, Form const & rhs){
    o << rhs.getName() << ", Form name";
    return o;
}

const char* Form::GradeTooLowException::what() const throw(){
    return("GradeTooLowException");
}

const char* Form::GradeTooHighException::what() const throw(){
    return("GradeTooHighException");
}

const char* Form::AlreadySignedException::what() const throw(){
    return("Already Signed");
}

void Form::beSigned(Bureaucrate & src){
    if(src.getGrade() > _grade_signed)
        throw GradeTooLowException();
    if(_signed == 1)
        throw AlreadySignedException();
    _signed = 1;
}
