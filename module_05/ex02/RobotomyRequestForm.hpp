#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
protected:
public:
    //format canonique
    RobotomyRequestForm(void);
    RobotomyRequestForm(RobotomyRequestForm const & src);
    RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
    ~RobotomyRequestForm();

    //additional constructor
    RobotomyRequestForm(std::string executor);
    //getter

    //functions
    void execute(Bureaucrat const & executor)const;
    
};

#endif