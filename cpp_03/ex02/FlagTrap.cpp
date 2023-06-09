/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:52:09 by jinam             #+#    #+#             */
/*   Updated: 2023/04/29 15:16:53 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"
#include <iostream>

FlagTrap::FlagTrap(void)
    : ClapTrap::ClapTrap("null", 100, 100, 30)
{
    std::cout << "FlagTrap "
              << "default constructor called" << std::endl;
}

FlagTrap::FlagTrap(std::string name)
    : ClapTrap::ClapTrap(name, 100, 100, 30)
{
    std::cout << "FlagTrap "
              << name << " constructor called" << std::endl;
}

FlagTrap::~FlagTrap()
{
    std::cout << "FlagTrap "
              << "destructor called" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap& ref)
{
    std::cout << "FlagTrap "
              << "copy constructor called" << std::endl;
    *this = ref;
}

FlagTrap& FlagTrap::operator=(const FlagTrap& ref)
{
    this->name = ref.name;
    this->hit_point = ref.hit_point;
    this->energy_point = ref.energy_point;
    this->attack_damage = ref.attack_damage;
    return (*this);
}

void FlagTrap::highFivesGuys(void)
{
    std::cout << "FlagTrap "
              << "buff highFives" << std::endl;
}
