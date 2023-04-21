/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jh <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:24:06 by jh                #+#    #+#             */
/*   Updated: 2023/04/22 01:09:58 by jh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point &p)
{
	*this = p;
}

Point	&Point::operator=(const Point &p)
{
	if (&p != this)
	{
		const_cast <Fixed &> (this->x) = p.getX();
		const_cast <Fixed &> (this->y) = p.getY();
	}
	return (*this);
}

Point::~Point(void)
{
}

Fixed	Point::getX(void) const
{
	return (x);
}

Fixed	Point::getY(void) const
{
	return (y);
}
