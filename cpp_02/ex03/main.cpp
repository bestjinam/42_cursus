/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jh <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:39:31 by jh                #+#    #+#             */
/*   Updated: 2023/04/22 02:25:44 by jh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int	main(void)
{
    Point x = Point(0, 0);
    Point y = Point(0, 5);
    Point z = Point(5, 0);

    std::cout << "TRUE NEWS" << std::endl;
	std::cout << "0, 0 : " << bsp(x, y, z, Point(0, 0)) << std::endl;
	std::cout << "1, 1 : " << bsp(x, y, z, Point(1, 1)) << std::endl;
	std::cout << "1, 2 : " << bsp(x, y, z, Point(1, 2)) << std::endl;
	std::cout << "1, 3 : " << bsp(x, y, z, Point(1, 3)) << std::endl;
	std::cout << "2, 0 : " << bsp(x, y, z, Point(2, 0)) << std::endl;
	std::cout << "2, 1 : " << bsp(x, y, z, Point(2, 1)) << std::endl;
	std::cout << "2, 3 : " << bsp(x, y, z, Point(2, 3)) << std::endl;
	std::cout << "3, 0 : " << bsp(x, y, z, Point(3, 0)) << std::endl;
	std::cout << "3, 1 : " << bsp(x, y, z, Point(3, 1)) << std::endl;
	std::cout << "3, 2 : " << bsp(x, y, z, Point(3, 2)) << std::endl;
	std::cout << "4, 0 : " << bsp(x, y, z, Point(4, 0)) << std::endl;
	std::cout << "5, 0 : " << bsp(x, y, z, Point(5, 0)) << std::endl;

	std::cout << "FAKE NEWS" << std::endl;
	std::cout << "5, 1 : " << bsp(x, y, z, Point(5, 1)) << std::endl;
	std::cout << "4, 2 : " << bsp(x, y, z, Point(4, 2)) << std::endl;
	std::cout << "3, 3 : " << bsp(x, y, z, Point(3, 3)) << std::endl;
	std::cout << "2, 4 : " << bsp(x, y, z, Point(2, 4)) << std::endl;
	std::cout << "1, 5 : " << bsp(x, y, z, Point(1, 5)) << std::endl;
	return 0;
}
