/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:22:18 by alprival          #+#    #+#             */
/*   Updated: 2023/03/24 15:55:41 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    {
        Fixed a(5.05f);
        Fixed c(2);
        std::cout << "The 6 comparison operators :" << std::endl;
        std::cout << "a = " << a << "\t" << "c = " << c << std::endl;
        std::cout << "a > c:";
        if(a > c)
            std::cout << "true " << std::endl;
        else
            std::cout << "false " << std::endl;

        std::cout << "a < c:";
        if(a < c)
            std::cout << "true " << std::endl;
        else
            std::cout << "false " << std::endl;

        std::cout << "a <= c:";
        if(a <= c)
            std::cout << "true " << std::endl;
        else
            std::cout << "false " << std::endl;

        std::cout << "a >= c:";
        if(a >= c)
            std::cout << "true " << std::endl;
        else
            std::cout << "false " << std::endl;

        std::cout << "a == c:";
        if(a == c)
            std::cout << "true " << std::endl;
        else
            std::cout << "false " << std::endl;


        std::cout << "a != c:";
        if(a != c)
            std::cout << "true " << std::endl;
        else
            std::cout << "false " << std::endl;
        
    }
        std::cout << std::endl;
    {

        Fixed a(5.05f);
        Fixed c(2);
        std::cout <<  a << " " <<  c << std::endl;
        std::cout << "The 4 arithmetic operators :" << std::endl;
        std::cout << "a + c:"<<  a + c << std::endl;
        std::cout << "a - c:"<<  a - c << std::endl;
        std::cout << "a * c:"<<  a * c << std::endl;
        std::cout << "a / c:"<<  a / c << std::endl;
    }
        std::cout << std::endl;
    {
        Fixed a;
        Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << "The 4 increment/decrement :" << std::endl;
        std::cout << "a:\t"<<  a << std::endl;
        std::cout << "++a:\t"<<  ++a << std::endl;
        std::cout << "a:\t"<<  a << std::endl;
        std::cout << "a++:\t"<<  a++ << std::endl;
        std::cout << "a:\t"<<  a << std::endl;
        std::cout << "a--:\t"<<  a-- << std::endl;
        std::cout << "a:\t"<<  a << std::endl;
        std::cout << "--a:\t"<<  --a << std::endl;
        std::cout << "a:\t"<<  a << std::endl;
        std::cout << "b:\t"<<  b << std::endl;
    }
        std::cout << std::endl;
    {
        Fixed const a(30);
        Fixed const b(10);
        std::cout << "Const max/min :" << std::endl;
        std::cout << "max :" << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
        std::cout << "min :" << std::endl;
        std::cout << Fixed::min( a, b ) << std::endl;
    }
        std::cout << std::endl;
    {
        Fixed a(30);
        Fixed b(10);
        std::cout << "Simple max/min :" << std::endl;
        std::cout << "max :" << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
        std::cout << "min :" << std::endl;
        std::cout << Fixed::min( a, b ) << std::endl;
    }
    // std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}