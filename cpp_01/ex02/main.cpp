/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:54:17 by jinam             #+#    #+#             */
/*   Updated: 2023/04/18 14:03:39 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str1("HI THIS IS BRAIN");
	std::string	*str1_ptr = &str1;
	std::string	&str1_ref = str1;

	std::cout << "*** print memory ***" << std::endl;
	std::cout << "str address : " << &str1 << std::endl;
	std::cout << "str_ptr address : " << &str1_ptr << std::endl;
	std::cout << "str_ref address : " << &str1_ref << std::endl;
	std::cout << std::endl;
	std::cout << "*** print memory variable ***" << std::endl;
	std::cout << "str : " << str1 << std::endl;
	std::cout << "str_ptr : " << *str1_ptr << std::endl;
	std::cout << "str_ref : " << str1_ref << std::endl;
}
