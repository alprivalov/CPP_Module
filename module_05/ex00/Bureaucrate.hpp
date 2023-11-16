#ifndef Bureaucrate_HPP
#define Bureaucrate_HPP

#include <iostream>
#include <string>
#include "exception"

class Bureaucrate
{
private:
    std::string const _name;
    int _grade;
protected:
public:
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
    //format canonique
    Bureaucrate(void);
    Bureaucrate(std::string name, int grade);
    Bureaucrate(Bureaucrate const & src);
    Bureaucrate & operator=(Bureaucrate const & rhs);
    virtual ~Bureaucrate();
    
    //getter
    std::string getName()const;
    int getGrade()const;
    //functions
    void    decrement_grade();
    void    increment_grade();
};
std::ostream & operator<<(std::ostream & o, Bureaucrate const & rhs);

#endif