/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jh <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:16:22 by jh                #+#    #+#             */
/*   Updated: 2023/04/22 01:09:48 by jh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &f1);
	Point &operator=(const Point &);
	~Point();

	//useful functions
	Fixed		getX(void) const;
	Fixed		getY(void) const;
private:
	Fixed const	x;
	Fixed const	y;
	
};

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &p);

#endif
