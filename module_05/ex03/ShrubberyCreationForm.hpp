#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
protected:
public:
    //format canonique
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(ShrubberyCreationForm const & src);
    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
    ~ShrubberyCreationForm();

    //additional constructor
    ShrubberyCreationForm(std::string executor);
    //getter

    //functions
    void execute(Bureaucrat const & executor)const;
    void print_tree_fd(std::string _target)const;
};

#endif