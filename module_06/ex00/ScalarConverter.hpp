#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <string>
#define FLOAT 1
#define INT 2
#define DOUBLE 3
#define CHAR 4
#include <limits.h>
#include <stdlib.h>
class ScalarConverter
{
private:
    class WrongSettingException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
protected:
public:
    //format canonique
    ScalarConverter(void);
    ScalarConverter(ScalarConverter const & src);
    ScalarConverter & operator=(ScalarConverter const & rhs);
    ~ScalarConverter();

    //additional constructor
   
    //getter

    //functions
    static void checker_settings(int ac);
    static void convert(std::string str);
};
std::ostream & operator<<(std::ostream & o, ScalarConverter const & rhs);

#endif