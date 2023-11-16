#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm",145,137)
{
    _target = "Default";
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string executor): AForm("ShrubberyCreationForm",145,137)
{
    _target = executor;
    std::cout << "ShrubberyCreationForm parametric constructor called" << std::endl;
    return ;
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): AForm(src)
{
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
    *this = src;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
    return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs){
    if(this != &rhs)
    {
        _target = rhs._target;
    }
    std::cout << " Copy assignment operator called ShrubberyCreationForm" << std::endl;
    return *this;
}
void ShrubberyCreationForm::print_tree_fd(std::string _target)const{
    std::ofstream   outfile;
    std::string     tmp;
    char*           fd_out;
    
    tmp = _target;
    tmp.append("_shrubbery");
	fd_out = const_cast<char*>(tmp.c_str());
    outfile.open(fd_out);
    outfile << "       _-_\n" << "    /~~   ~~\\\n" << " /~~         ~~\\\n" << "{               }\n" <<"   _-     -_  /\n" <<"   ~  \\   /  ~\n" <<"_- -   | | _- _\n" <<"  _ -  | |   -_\n" << "      /   \\\n";
    outfile << std::endl;
    outfile << "       _-_\n" << "    /~~   ~~\\\n" << " /~~         ~~\\\n" << "{               }\n" <<"   _-     -_  /\n" <<"   ~  \\   /  ~\n" <<"_- -   | | _- _\n" <<"  _ -  | |   -_\n" << "      /   \\\n";
    std::cout << *this << "writes ASCII trees inside " << tmp << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)const{
    try
    {
        AForm::execute(executor);
        print_tree_fd(_target);
    }
    catch(const std::exception& e)
    {
        std::cout << *this << " failed to writes ASCII trees inside it because " << e.what() << std::endl;
    }
}