/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-1.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jh <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:06:15 by jh                #+#    #+#             */
/*   Updated: 2023/04/13 20:08:23 by jh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	int	arr_size;

	std::cout << "array size : ";
	std::cin >> arr_size;
	int	*list = new int[arr_size];
	for (int i = 0; i < arr_size; i ++)
	{
	  std::cin >> list[i];
	}
	for (int i = 0; i < arr_size; i ++)
	{
	  std::cout << i << "th element of list : " << list[i] << std::endl;
	}
	delete [] list;
	return (0);
}
