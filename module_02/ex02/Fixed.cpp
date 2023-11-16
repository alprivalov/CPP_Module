/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:22:12 by alprival          #+#    #+#             */
/*   Updated: 2023/03/24 15:22:31 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _n(0)
{
    // std::cout << "Construct called" << std::endl;
    return;
}

Fixed::Fixed(int const n): _n(n << _n_bits)
{
    // std::cout << "Parametric construct called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const & src)
{
    // std::cout << "Copy construct called" << std::endl;
    *this = src;
    return;
}

Fixed::Fixed(float const Raw):_n(roundf(Raw * (1 << _n_bits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
    return ;
}

int     Fixed::getRawBits(void) const{
    return this->_n;
}

float Fixed::toFloat(void) const
{
	return ((float)(this->_n) / (1 << _n_bits));
}

int Fixed::toInt(void) const
{
	return this->_n >> _n_bits;
}

Fixed & Fixed::operator=(Fixed const & rhs){
    if(this != &rhs)
        this->_n = rhs.getRawBits();
    return *this;
}

std::ostream & operator<< (std::ostream & o, Fixed const & rhs){
    o << rhs.toFloat();
    return o;

}

Fixed& Fixed::operator++()
{
    _n++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return(tmp);
}

Fixed& Fixed::operator--()
{
    _n--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return(tmp);
}

bool Fixed::operator==(const Fixed& rhs){
   return((_n == rhs._n) ? true : false);
}

bool Fixed::operator!=(const Fixed& rhs){
   return((_n != rhs._n) ? true : false);
}


bool Fixed::operator>(const Fixed& rhs){
   return((_n > rhs._n) ? true : false);
}

bool Fixed::operator<(const Fixed& rhs){
    return((_n < rhs._n) ? true : false); 
}

bool Fixed::operator>=(const Fixed& rhs){
    return((_n >= rhs._n) ? true : false);
}

bool Fixed::operator<=(const Fixed& rhs){
    return((_n <= rhs._n) ? true : false);
}

Fixed Fixed::operator+(const Fixed& rhs)const{
    return(toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs)const{
    return(toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs)const{
    return(toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs)const{
    return(toFloat() / rhs.toFloat());
}

Fixed & Fixed::max(Fixed & a, Fixed & b){
    if(a > b)
        return(a);
    return(b);
    // return((a.toFloat() > b.toFloat()) ? a : b);
}

Fixed & Fixed::min(Fixed & a, Fixed & b){
    if(a > b)
        return(b);
    return(a);
    // return((a.toFloat() > b.toFloat()) ? a : b);
}

const Fixed & Fixed::min(Fixed const & a, Fixed const & b){
    if(a.getRawBits() > b.getRawBits())
        return(b);
    return(a);
}

const Fixed & Fixed::max(Fixed const & a, Fixed const & b){
    if(a.getRawBits() > b.getRawBits())
        return(a);
    return(a);
}
