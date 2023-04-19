/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ifile.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:12:51 by jinam             #+#    #+#             */
/*   Updated: 2023/04/19 16:44:00 by jinam            ###   ########.fr       */
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
	const size_t	s1_len = s1.length();

	fidx = data.find(s1, 0);
	while (fidx != std::string::npos)
	{
		data.erase(fidx, s1_len);
		data.insert(fidx, s2);
		fidx = data.find(s1, fidx + s2.length());
	}
}

int		Ifile::write(std::string f1)
{
	std::ofstream	fout;

	fout.open(f1 + ".replace");
	fout << data;
	fout.close();
	return (0);
}
