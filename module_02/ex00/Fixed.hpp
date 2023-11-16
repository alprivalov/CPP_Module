/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:21:18 by alprival          #+#    #+#             */
/*   Updated: 2023/03/24 15:22:59 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#ifndef FIXED_H
#define FIXED_H
class Fixed
{
private:
    int _n;
	int const static _n_bits;
public:
   Fixed(void);
    Fixed(int const n);
    Fixed(Fixed const & src);
    ~Fixed();
    int getRawBits(void)const;
    void setRawBits( int const raw );
    Fixed & operator=(Fixed const & rhs);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
