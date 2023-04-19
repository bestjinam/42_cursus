/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:05:07 by jinam             #+#    #+#             */
/*   Updated: 2023/04/19 21:23:49 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	h;

	std::cout << ">> DEBUG <<" << std::endl;
	h.complain("DEBUG");
	std::cout << std::endl;
	std::cout << ">> INFO <<" << std::endl;
	h.complain("INFO");
	std::cout << std::endl;
	std::cout << ">> WARNING <<" << std::endl;
	h.complain("WARNING");
	std::cout << std::endl;
	std::cout << ">> ERROR <<" << std::endl;
	h.complain("ERROR");
	std::cout << std::endl;
}
