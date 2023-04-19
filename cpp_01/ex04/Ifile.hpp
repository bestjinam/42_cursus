/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ifile.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:32:09 by jinam             #+#    #+#             */
/*   Updated: 2023/04/18 21:15:28 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IFILE_HPP
# define IFILE_HPP
# include <fstream>
# include <iostream>
# include <string>

class Ifile
{
private:
	std::ifstream 	readFile;
	std::string		data;
	std::string		replaced;
public:
	Ifile();
	Ifile(std::string name);
	~Ifile();
	void	read(void);
	void	replace(std::string s1, std::string s2);
	std::string	getString(void);
};
#endif
