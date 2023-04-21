/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jh <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:21:09 by jh                #+#    #+#             */
/*   Updated: 2023/04/21 13:04:42 by jh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	fix = 0;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	fix = (num << fractional_bits);
}

Fixed::Fixed(float num)
{
	std::cout << "Float constructor called" << std::endl;
	fix = ((int) roundf(num * (1 << fractional_bits)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fix = f.getRawBits();
	return (*this);
}

int	Fixed::toInt(void) const
{
	return (fix >> fractional_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float) fix / (1<<fractional_bits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (fix);
}

void	Fixed::setRawBits(const int raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	fix = raw;
}

