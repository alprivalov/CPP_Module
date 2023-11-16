#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    //  init bureaucrate
    srand(time( NULL ));
    std::cout <<"-----------------------constructor intern-----------------------" <<std::endl;
    Intern      intern;

    std::cout <<"-----------------------constructor bureaucrate-----------------------" <<std::endl;
    Bureaucrat bureaucrat1;
    Bureaucrat bureaucrat2("Kevin", 5);
    Bureaucrat bureaucrat3("Bob", 150);

    std::cout <<"-----------------------constructor intern form-----------------------" <<std::endl;
    AForm *PresidentialPardonForm = intern.makeForm("PresidentialPardonForm","Obama");
    AForm *RobotomyRequestForm = intern.makeForm("RobotomyRequestForm","Robot");
    AForm *ShrubberyCreationForm = intern.makeForm("ShrubberyCreationForm","Jardin");
    

    std::cout << std::endl << std::endl <<"-----------------------sign PresidentialPardonForm-----------------------" <<std::endl;
    bureaucrat1.signForm(*PresidentialPardonForm);
    bureaucrat2.signForm(*PresidentialPardonForm);
    bureaucrat3.signForm(*PresidentialPardonForm);
    
    std::cout << std::endl <<"-----------------------sign RobotomyRequestForm-----------------------" <<std::endl;
    bureaucrat1.signForm(*RobotomyRequestForm);
    bureaucrat2.signForm(*RobotomyRequestForm);
    bureaucrat3.signForm(*RobotomyRequestForm);

    std::cout << std::endl <<"-----------------------sign ShrubberyCreationForm-----------------------" <<std::endl;
    bureaucrat1.signForm(*ShrubberyCreationForm);
    bureaucrat2.signForm(*ShrubberyCreationForm);
    bureaucrat3.signForm(*ShrubberyCreationForm);

    std::cout << std::endl << std::endl <<"-----------------------execute PresidentialPardonForm-----------------------" <<std::endl;
    bureaucrat1.executeForm(*PresidentialPardonForm);
    bureaucrat2.executeForm(*PresidentialPardonForm);
    bureaucrat3.executeForm(*PresidentialPardonForm);

    std::cout << std::endl <<"-----------------------execute RobotomyRequestForm-----------------------" <<std::endl;
    bureaucrat1.executeForm(*RobotomyRequestForm);
    bureaucrat2.executeForm(*RobotomyRequestForm);
    bureaucrat3.executeForm(*RobotomyRequestForm);

    std::cout << std::endl <<"-----------------------execute ShrubberyCreationForm-----------------------" <<std::endl;
    bureaucrat1.executeForm(*ShrubberyCreationForm);
    bureaucrat2.executeForm(*ShrubberyCreationForm);
    bureaucrat3.executeForm(*ShrubberyCreationForm);

    std::cout << std::endl <<"-----------------------execute inextisting_form-----------------------" <<std::endl;
    try
    {
        AForm *inextisting_form = intern.makeForm("inextisting_form","Jardin");
        bureaucrat1.executeForm(*inextisting_form);
        bureaucrat2.executeForm(*inextisting_form);
        bureaucrat3.executeForm(*inextisting_form);
    }
    catch(std::exception & e)
    {
        std::cerr << "Cannot execute the program because :" <<e.what() << std::endl;
    }
    std::cout << std::endl << std::endl << "-----------------------destructor-----------------------" <<std::endl;
    delete PresidentialPardonForm;
    delete RobotomyRequestForm;
    delete ShrubberyCreationForm;
}