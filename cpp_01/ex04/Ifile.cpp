/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ifile.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:12:51 by jinam             #+#    #+#             */
/*   Updated: 2023/04/18 21:40:37 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ifile.hpp"
#include <sstream>

Ifile::Ifile()
{
}

Ifile::Ifile(std::string name)
{
	readFile.open(name);
}

Ifile::~Ifile()
{
}

void	Ifile::read(void)
{
	std::stringstream	ss;

	if (readFile.is_open())
	{
		ss << readFile.rdbuf();
		data = ss.str();
	}
	else
	{
		std::cerr << "Could not open the file" << std::endl;
		exit(EXIT_FAILURE);
	}
	readFile.close();
}

void	Ifile::replace(std::string s1, std::string s2)
{
	size_t	fidx;

	(void) s2;
	(void) s1;
	std::cout << data;
}
