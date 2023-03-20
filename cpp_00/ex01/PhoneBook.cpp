/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:06:33 by jinam             #+#    #+#             */
/*   Updated: 2023/03/18 16:41:07 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void)
{
	last_idx = -1;
}

void	PhoneBook::add(void)
{
	last_idx = (last_idx + 1) % 8;
	contacts[last_idx].set_info();
}

void	PhoneBook::show_table(void)
{
	int	i;
	int	j;
	std::string field[4] = {"index", "first name", "last name", "nickname"};

	i = 0;
	while (i != 4)
	{
		std::cout << "|";;
		std::cout << std::setw(10);
		std::cout << field[i];
		i ++;
	}
	std::cout << std::endl;
	i = 0;
	while (i != last_idx + 1)
	{
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << i;
		j = 0;
		while (j != 3)
		{
			std::cout << "|";
			contacts[i].print_field(j);
			j ++;
		}
		std::cout << std::endl;
		i ++;
	}
	std::cout << std::endl;
}

void	PhoneBook::search(void)
{
	int	i;
	int	pick;

	i = 0;
	std::cout << "Contacts list" << std::endl;
	show_table();
	std::cout << "pick idx : " << std::endl;
	std::cin >> pick;
	std::cin.ignore();
	if (pick > last_idx)
	{
		std::cout << "Wrong index. Try again!" << std::endl;
		search();
	}
	else
		contacts[pick].display(pick);
}
