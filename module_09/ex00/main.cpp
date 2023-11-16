#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av){
    BitcoinExchange    database;
    if(ac != 2)
    {
        std::cout << "Error : wrong number of argument" << std::endl;
        return (1);
    }
    try
    {
        database.init_database(av,DATA);
        database.init_database(av,INPUT);
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
