#include "AForm.hpp"

AForm::AForm(void): _signed(0), _grade_signed(75),_grade_execute(75)
{
    std::cout << "AForm Default constructor called" << std::endl;
    return ;
}

AForm::AForm(std::string name, int grade_signed, int grade_execute): name(name), _signed(0),_grade_signed(grade_signed),_grade_execute(grade_execute)
{
    std::cout << "AForm Copy parametric constructor called" << std::endl;
    return ;
}

AForm::AForm(AForm const & src): name(src.name),_grade_signed(src._grade_signed),_grade_execute(src._grade_execute)
{
    std::cout << "AForm Copy constructor called" << std::endl;
    *this = src;
    return ;
}

AForm::~AForm()
{
    std::cout << "AForm Destructor called" << std::endl;
    return ;
}

AForm & AForm::operator=(AForm const & rhs){
    std::cout << "AForm Copy assignment operator called" << std::endl;
    if(this != &rhs)
        _signed = rhs._signed;
    return *this;
}

std::string AForm::getName()const{
    return (name);
}

std::ostream & operator<< (std::ostream & o, AForm const & rhs){
    o << "Form name : " << rhs.getName() << " is Signed :" << rhs.isSigned() << " grade Execute : " << rhs.gradeExecute() << " grade Signed : " << rhs.gradeSigned();
    return o;
}

const char* AForm::SignedGradeTooLowException::what() const throw(){
    return("Signed Grade Too Low");
}

const char* AForm::NotSignedException::what() const throw(){
    return("Already Signed");
}

const char* AForm::ExecuteGradeTooLowException::what() const throw(){
    return("Execute Grade Too Low");
}

const char* AForm::AlreadySignedException::what() const throw(){
    return("Already Signed");
}
void AForm::beSigned(Bureaucrat & src){
    if(src.getGrade() > _grade_signed)
        throw SignedGradeTooLowException();
    if(_signed == 1)
        throw AlreadySignedException();
    std::cout << src <<  " signed" << *this << std::endl;
    _signed = 1;
}

int AForm::isSigned()const{
   return _signed;
}

int AForm::gradeExecute()const{
    return _grade_execute;
}

int AForm::gradeSigned()const{
    return _grade_signed;
}


void AForm::execute(Bureaucrat const & executor)const{
    if(isSigned() == 0)
        throw NotSignedException();
    if(gradeSigned() < executor.getGrade())
        throw SignedGradeTooLowException();
    if(gradeExecute() < executor.getGrade())
        throw ExecuteGradeTooLowException();
}