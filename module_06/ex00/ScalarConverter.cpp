/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:20:50 by alprival          #+#    #+#             */
/*   Updated: 2023/03/24 15:21:00 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::checker_settings(int ac){
    if (ac != 2)
        throw WrongSettingException();
}

ScalarConverter::ScalarConverter(void)
{

    std::cout << "ScalarConverter Default constructor called" << std::endl;
    return ;
}

const char* ScalarConverter::WrongSettingException::what() const throw(){
    return("Error :Bad parametre");
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    std::cout << "ScalarConverter Copy constructor called" << std::endl;
    *this = src;
    return ;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter Destructor called" << std::endl;
    return ;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs){
    std::cout << " Copy assignment operator called ScalarConverter" << std::endl;
    (void)rhs;
    return *this;
}

int str_compare(std::string str){
    if(str.compare("nan") || str.compare("nanf")  || str.compare("-nanf") || str.compare("-inf"))
        return(1);
    return(0);
}

void ScalarConverter::convert(std::string str){

    double   result_double;
    char*    endptr;
    int      index;

    result_double = strtod(str.c_str(), &endptr);

    if (*endptr == 'f')
    {
        if((endptr[1]))
        {   
            std::cout << "Error: bad parametre" << std::endl;
            throw WrongSettingException();
        }
    }
    else if(*endptr && str.size() != 1)
    {
        std::cout << "Error: bad parametre" << std::endl;
        throw WrongSettingException();
    }
    index = str.find('.');

    //char
    std::cout << "char: ";
    if (result_double >= ' ' && result_double <= '~')
    {
        std::cout << "'" << static_cast<char>(result_double) << "'" << std::endl;
    }
    else if(str.size()== 1 && str[0] >= ' ' && str[0] <= '~')
    {
        std::cout << "'" << static_cast<char>(str[0]) << "'" << std::endl;
    }
    else if(result_double > 127 || str_compare(str))
        std::cout << "impossible" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    //int
    std::cout << "int: ";
    if (result_double <= INT_MAX && result_double >=  INT_MIN)
    {
        std::cout << static_cast<int>(result_double) << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
    
    //float
    if((index != -1 && str[index + 1] != '0') || result_double > 1e6 || result_double < 0 || str_compare(str))
        std::cout << "float: " <<  static_cast<float>(result_double) << "f" << std::endl;
    else
        std::cout << "float: " <<  static_cast<float>(result_double) << ".0" << "f" << std::endl;
    
    //double
    if((index != -1 && str[index + 1] != '0') || result_double > 1e6 || result_double < 0 || str_compare(str))
        std::cout << "double: " <<  static_cast<double>(result_double) << std::endl;
    else
        std::cout << "double: " <<  static_cast<double>(result_double) << ".0" << "f" << std::endl;
    // std::cout << "type: " << type << std::endl;
}
