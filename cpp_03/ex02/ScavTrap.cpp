/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:09:57 by jinam             #+#    #+#             */
/*   Updated: 2023/04/27 19:10:44 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
    : ClapTrap::ClapTrap("null", 100, 50, 20)
{
    std::cout << "ScavTrap "
              << "default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string n)
    : ClapTrap::ClapTrap(n, 100, 50, 20)
{
    std::cout << "ScavTrap "
              << n << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap "
              << "destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref)
{
    std::cout << "ScavTrap "
              << "copy constructor called" << std::endl;
    *this = ref;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref)
{
    this->name = ref.name;
    this->hit_point = ref.hit_point;
    this->energy_point = ref.energy_point;
    this->attack_damage = ref.attack_damage;
    return (*this);
}

void ScavTrap::guardGate(void)
{
    if (energy_point == 0 || hit_point == 0)
    {
        std::cout << "ScavTrap " << name << " can't do anything !" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " has entered gate guard mode" << std::endl;
    energy_point--;
}

void ScavTrap::attack(const std::string& target)
{
    if (energy_point == 0 || hit_point == 0)
    {
        std::cout << "ScavTrap " << name << " can't do anything !" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage" << std::endl;
    energy_point--;
}
