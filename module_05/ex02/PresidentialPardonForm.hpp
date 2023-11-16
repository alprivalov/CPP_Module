#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
protected:
public:
    //format canonique
    PresidentialPardonForm(void);
    PresidentialPardonForm(PresidentialPardonForm const & src);
    PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
    ~PresidentialPardonForm();

    //additional constructor
    PresidentialPardonForm(std::string executor);
    //getter

    //functions
    void execute(Bureaucrat const & executor)const;
    
};

#endif