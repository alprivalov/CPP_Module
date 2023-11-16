#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include "Bureaucrate.hpp"
#include <string>

class Bureaucrate;

class Form
{
private:
    std::string const name;
    bool _signed;
    int const _grade_signed;
    int const _grade_execute;
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
    class AlreadySignedException : public std::exception
    {
        public :
            virtual const char* what() const throw(); 
    };
protected:
public:
    //format canonique
    Form(void);
    Form(std::string name, int grade_signed ,int grade_execute);
    Form(Form const & src);
    Form & operator=(Form const & rhs);
    virtual ~Form();
    
    //getter
    std::string getName()const;
    //functions
    void beSigned(Bureaucrate & src);
};
std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif