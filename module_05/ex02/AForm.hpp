#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm
{
private:
    std::string const name;
    bool _signed;
    int const _grade_signed;
    int const _grade_execute;
    class SignedGradeTooLowException : public std::exception
    {
        public :
            virtual const char* what() const throw(); 
    };
    class NotSignedException : public std::exception
    {
        public :
            virtual const char* what() const throw(); 
    };
    class AlreadySignedException : public std::exception
    {
        public :
            virtual const char* what() const throw(); 
    };
    class ExecuteGradeTooLowException : public std::exception
    {
        public :
            virtual const char* what() const throw(); 
    };
protected:
public:
    //Aformat canonique
    AForm(void);
    AForm(std::string name, int grade_signed, int grade_execute);
    AForm(AForm const & src);
    AForm & operator=(AForm const & rhs);
    virtual ~AForm();
    
    //getter
    std::string getName()const;
    int         isSigned()const;
    int         gradeExecute()const;
    int         gradeSigned()const;
    //functions
    void beSigned(Bureaucrat & src);
    virtual void execute(Bureaucrat const & executor)const = 0;
};
std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif