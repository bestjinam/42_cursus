/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:30:04 by jinam             #+#    #+#             */
/*   Updated: 2023/03/18 16:38:17 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	select;

	while (1)
	{
		std::cout << "Hello! This is a phonebook" << std::endl;
		std::cout << "menu : 1. ADD 2. SEARCH 3. EXIT" << std::endl;
		std::getline(std::cin, select);
		if (select == "ADD")
			book.add();
		else if (select == "SEARCH")
			book.search();
		else if (select == "EXIT")
			break ;
		else
			std::cout << "Please choose right code" << std::endl;
	}
}
