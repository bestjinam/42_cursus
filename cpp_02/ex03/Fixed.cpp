/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jh <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:21:09 by jh                #+#    #+#             */
/*   Updated: 2023/04/21 19:13:51 by jh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	fix = 0;
}

Fixed::Fixed(const Fixed &f)
{
	*this = f;
}

Fixed::Fixed(int num)
{
	fix = (num << fractional_bits);
}

Fixed::Fixed(float num)
{
	fix = ((int) roundf(num * (1 << fractional_bits)));
}

Fixed::~Fixed(void)
{
}

Fixed	&Fixed::operator=(const Fixed &f)
{
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

//comparison
bool	Fixed::operator<(const Fixed &f) const
{
	return (fix < f.getRawBits());
}

bool	Fixed::operator>(const Fixed &f) const
{
	return (fix > f.getRawBits());
}

bool	Fixed::operator<=(const Fixed &f) const
{
	return (fix <= f.getRawBits());
}

bool	Fixed::operator>=(const Fixed &f) const
{
	return (fix >= f.getRawBits());
}

bool	Fixed::operator==(const Fixed &f) const
{
	return (fix == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed &f) const
{
	return (fix != f.getRawBits());
}

//arithmetic
Fixed	Fixed::operator+(const Fixed &f)
{
	Fixed res;

	res.setRawBits(this->fix + f.fix);
	return (res);
}

Fixed	Fixed::operator-(const Fixed &f)
{
	Fixed res;

	res.setRawBits(this->fix - f.fix);
	return (res);
}

Fixed	Fixed::operator*(const Fixed &f)
{
	Fixed	res(this->toFloat() * f.toFloat());

	return (res);
}

Fixed	Fixed::operator/(const Fixed &f)
{
	Fixed	res(this->toFloat() / f.toFloat());

	return (res);
}

//increment/decrement

Fixed	&Fixed::operator++(void)
{
	this->fix ++;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed	res(*this);

	this->fix++;
	return (res);
}

Fixed	&Fixed::operator--(void)
{
	this->fix --;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed	res(*this);

	this->fix--;
	return (res);
}

//min / max

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1 <= f2 ? f1 : f2);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1 >= f2 ? f1 : f2);
}

const Fixed	&Fixed::min(Fixed const &f1, Fixed const &f2)
{
	return (f1 <= f2 ? f1 : f2);
}

const Fixed	&Fixed::max(Fixed const &f1, Fixed const &f2)
{
	return (f1 >= f2 ? f1 : f2);
}


std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}
