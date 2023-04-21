/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jh <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:08:13 by jh                #+#    #+#             */
/*   Updated: 2023/04/22 02:27:06 by jh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed	fixedShoelaceFomula(const Point &p1, const Point &p2, const Point &p3)
{
	Fixed	res;

	res = (p1.getX() * p2.getY() + p2.getX() * p3.getY() + p3.getX() * p1.getY()) -
		(p1.getY() * p2.getX() + p2.getY() * p3.getX() + p3.getY() * p1.getX());
	if (res < 0)
		res = Fixed(-1) * res;
	return (res / 2);
}

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &p)
{
	Fixed	abc = fixedShoelaceFomula(a, b, c);
	Fixed	pab = fixedShoelaceFomula(p, a, b);
	Fixed	pac = fixedShoelaceFomula(p, a, c);
	Fixed	pbc = fixedShoelaceFomula(p, b, c);

	// std::cout << "abc: " << abc << std::endl;
	// std::cout << "pab: " << pab << std::endl;
	// std::cout << "pac: " << pac << std::endl;
	// std::cout << "pbc: " << pbc << std::endl;
	return (abc == (pab + pac + pbc));
}
