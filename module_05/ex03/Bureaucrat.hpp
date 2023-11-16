#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    std::string const _name ;
    int _grade;
    class GradeTooHighException : public std::exception
    {
        public :
            virtual const char* what() const throw(); 
    };
    class GradeTooLowException : public std::exception
    {
        public :
            virtual const char* what() const throw(); 
    };
protected:
public:
    //format canonique
    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const & src);
    Bureaucrat & operator=(Bureaucrat const & rhs);
    ~Bureaucrat();
    
    //getter
    std::string getName()const;
    int getGrade()const;
    //functions
    void    decrement_grade();
    void    increment_grade();
    void    signForm(AForm &form);
    void    executeForm(AForm const & form);
};
std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif