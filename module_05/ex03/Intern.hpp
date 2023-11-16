#ifndef Intern_HPP
#define Intern_HPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <string>

class Intern
{
private:
    class CannotCreateFormException : public std::exception
    {
        public :
            virtual const char* what() const throw(); 
    };
protected:
public:
    //format canonique
    Intern(void);
    Intern(Intern const & src);
    Intern & operator=(Intern const & rhs);
    ~Intern();

    //additional constructor
   
    //getter

    //functions
    AForm * makeForm(std::string form,std::string target);
};
std::ostream & operator<<(std::ostream & o, Intern const & rhs);

#endif