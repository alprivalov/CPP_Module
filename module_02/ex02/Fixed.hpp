/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:20:57 by alprival          #+#    #+#             */
/*   Updated: 2023/03/24 15:22:14 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#ifndef FIXED_H
#define FIXED_H
class Fixed
{
private:
    int _n;
    int const static _n_bits = 8;
public:
    Fixed(void);
    Fixed(int const n);
    Fixed(Fixed const & src);
    Fixed(float const Raw);
    ~Fixed();
    int getRawBits(void)const;
    int toInt( void ) const;
    float toFloat( void ) const;
    Fixed & operator=(Fixed const & rhs);

    bool operator==(const Fixed& rhs);
    bool operator!=(const Fixed& rhs);
    bool operator<=(const Fixed& rhs);
    bool operator>=(const Fixed& rhs);
    bool operator>(const Fixed& rhs);
    bool operator<(const Fixed& rhs);

    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    Fixed operator+(const Fixed& rhs)const;
    Fixed operator-(const Fixed& rhs)const;
    Fixed operator*(const Fixed& rhs)const;
    Fixed operator/(const Fixed& rhs)const;
    static Fixed & max(Fixed & a, Fixed & b);
    static Fixed & min(Fixed & a, Fixed & b);
    static const Fixed &  min(const Fixed &  a, const Fixed & b);
    static const Fixed &  max(const Fixed &  a, const Fixed & b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif