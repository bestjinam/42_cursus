/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jh <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:16:15 by jh                #+#    #+#             */
/*   Updated: 2023/04/21 19:13:56 by jh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(int num);
	Fixed(float num);
	Fixed(const Fixed &);
	~Fixed();
	Fixed				&operator=(const Fixed &f);
	//comparison operators
	bool				operator>(const Fixed &f) const;
	bool				operator<(const Fixed &f) const;
	bool				operator<=(const Fixed &f) const;
	bool				operator>=(const Fixed &f) const;
	bool				operator==(const Fixed &f) const;
	bool				operator!=(const Fixed &f) const;
	//arithmetic operators
	Fixed				operator+(const Fixed &f);
	Fixed				operator-(const Fixed &f);
	Fixed				operator*(const Fixed &f);
	Fixed				operator/(const Fixed &f);
	//increment/decrement
	Fixed				&operator++(void);
	const Fixed			operator++(int);
	Fixed 				&operator--(void);
	const Fixed			operator--(int);
	
	int					getRawBits(void) const;
	void				setRawBits(int const raw);

	float				toFloat(void) const;
	int					toInt(void) const;
	
	//min, max
	static Fixed		&min(Fixed &f1, Fixed &f2);
	static Fixed		&max(Fixed &f1, Fixed &f2);
	static const Fixed	&min(const Fixed &f1, const Fixed &f2);
	static const Fixed	&max(const Fixed &f1, const Fixed &f2);

private:
	int					fix;
	static const int	fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &);

#endif
