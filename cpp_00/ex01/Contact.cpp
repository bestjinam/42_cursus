/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:42:02 by jinam             #+#    #+#             */
/*   Updated: 2023/03/18 16:43:14 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

int		Contact::empty(void) const
{
	return (first_name.empty() || last_name.empty() || nickname.empty() \
	|| phone_number.empty() || darkest_secret.empty());
}

void	Contact::set_info(void)
{
	while (1)
	{
		std::cout << "please fill the information!" << std::endl;
		std::cout << "first name : ";
		std::getline(std::cin, first_name);
		std::cout << "last name : ";
		std::getline(std::cin, last_name);
		std::cout << "nickname : ";
		std::getline(std::cin, nickname);
		std::cout << "phone number : " ;
		std::getline(std::cin, phone_number);
		std::cout << "darkest secret : ";
		std::getline(std::cin, darkest_secret);
		if (!this->empty())
			break ;
		std::cout << "Error : wrong format! do it again!" << std::endl;
	}
}

void	Contact::print_field(int select)
{
	std::string	str;

	if (select == 0)
		str = first_name;
	else if (select == 1)
		str = last_name;
	else if (select == 2)
		str = nickname;
	else if (select == 3)
		str = phone_number;
	else if (select == 4)
		str = darkest_secret;
	std::cout << std::setw(10);
	if (str.length() > 10)
		std::cout << str.substr(0, 9) + '.';
	else
		std::cout << str;
}

void	Contact::display(int idx) const
{
	std::cout << "Idx : " << idx << std::endl;
	std::cout << "First_name : " << first_name << std::endl;
	std::cout << "Last_name : " << last_name << std::endl;
	std::cout << "Nickname : " << nickname << std::endl;
	std::cout << "Darkest secret : " << darkest_secret << std::endl;
}
