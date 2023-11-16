#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    std::string copy_av;

    try
    {
        ScalarConverter::checker_settings(ac);
        copy_av.append(av[1]);
        ScalarConverter::convert(copy_av);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Couldn't start because " << e.what() << '\n';
    }
    
}