/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:53:30 by jinam             #+#    #+#             */
/*   Updated: 2023/04/19 21:41:11 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

static int		_get_level(std::string level)
{
	const std::string	tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;

	i = 0;
	while (i != 4)
	{
		if (level.compare(tab[i]) == 0)
			return (i);
		i ++;
	}
	return (-1);
}

void	Harl::complain(std::string level)
{
	fptr	ff[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	const	std::string	tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int		lv = _get_level(level);
	//fptr	f;
	//f = &Harl::debug;
	if (lv == -1)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
	while (lv != 4)
	{
		std::cout << "[ " + tab[lv] + " ]" << std::endl;
		(this->*ff[lv])();
		std:: cout << std::endl;
		lv ++;
	}
}
