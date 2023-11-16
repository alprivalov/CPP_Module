/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:21:10 by alprival          #+#    #+#             */
/*   Updated: 2023/03/24 15:23:14 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _n(0)
{
    std::cout << "Default constructor called " << std::endl;
    return;
}

Fixed::Fixed(int const n): _n(n)
{
    std::cout << "Constructor parametric called Fixed " << std::endl;
    return;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called " << std::endl;
    return ;
}

int     Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called " << std::endl;
    return this->_n;
}

Fixed & Fixed::operator=(Fixed const & rhs){
    std::cout << "Copy assignment operator called " << std::endl;
    if(this != &rhs)
        this->_n = rhs.getRawBits();
    return *this;
}

std::ostream & operator<< (std::ostream & o, Fixed const & rhs){
    o <<  "the value of fixed is :" << rhs.getRawBits();
    return o;

}

void Fixed::setRawBits( int const raw ){
    _n = raw;
}