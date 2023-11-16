/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:21:41 by alprival          #+#    #+#             */
/*   Updated: 2023/03/24 15:21:51 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _n(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(int const n): _n(n << _n_bits)
{
    std::cout << "Int constructor called" << std::endl;
    return;
}

Fixed::Fixed(float const rhs)
{
	std::cout << "Float constructor called" << std::endl;
	this->_n = int(roundf(rhs * (1 << _n_bits)));
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

float Fixed::toFloat(void) const
{
	return float(this->_n) / (1 << _n_bits);
}

int Fixed::toInt(void) const
{
	return this->_n >> _n_bits;
}

int     Fixed::getRawBits(void) const{
    return this->_n;
}

Fixed & Fixed::operator=(Fixed const & rhs){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &rhs)
        this->_n = rhs.getRawBits();
    return *this;
}

std::ostream & operator<< (std::ostream & o, Fixed const & rhs){
	o << rhs.toFloat();
    return o;

}