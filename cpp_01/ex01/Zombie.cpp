/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:50:36 by jinam             #+#    #+#             */
/*   Updated: 2023/04/16 22:00:21 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void    Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::Zombie(std::string n)
{
	name = n;
}

Zombie::Zombie()
{}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed..." << std::endl;
}
