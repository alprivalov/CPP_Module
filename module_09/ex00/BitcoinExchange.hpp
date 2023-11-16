#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#define  DATA 1
#define  INPUT 2
#define  YEAR 3
#define  MONTH 4
#define  DAY 5
class BitcoinExchange
{
private:
    std::map<int, float> map_data;
    void exceptionchecker(std::string line, int type);
    
    class CannotOpenFdException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
    class WrongDateException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
    class WrongDateFormatException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
    class WrongValueException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
    class TooTargeANumberException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
    class NotAPositiveNumberException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
    class NotYetCreatedException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
protected:
public:
    //format canonique
    BitcoinExchange(void);
    BitcoinExchange(BitcoinExchange const & src);
    BitcoinExchange & operator=(BitcoinExchange const & rhs);
    ~BitcoinExchange();

    //additional constructor
   
    //getter

    //functions
    void    parsing_input(int type, std::string line);
    void    init_database(char **av,int type);
    void    print_database();
    int     string_to_int(int type, std::string line);
    float     string_to_float(int type,std::string line);
    

};
std::ostream & operator<<(std::ostream & o, BitcoinExchange const & rhs);

#endif