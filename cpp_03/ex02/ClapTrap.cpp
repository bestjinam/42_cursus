/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:15:27 by jinam             #+#    #+#             */
/*   Updated: 2023/04/27 19:11:02 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void)
    : name("null"), hit_point(10), energy_point(10), attack_damage(0)
{
    std::cout << "ClapTrap "
              << "default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string n)
    : name(n), hit_point(10), energy_point(10), attack_damage(0)
{
    std::cout << "ClapTrap "
              << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string n, int h, int energy, int attack)
    : name(n), hit_point(h), energy_point(energy), attack_damage(attack)
{
    std::cout << "ClapTrap "
              << name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap "
              << name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
    std::cout << "ClapTrap "
              << "copy constructor called" << std::endl;
    *this = ref;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
    this->name = ref.name;
    this->hit_point = ref.hit_point;
    this->attack_damage = ref.attack_damage;
    this->energy_point = ref.energy_point;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_point == 0 || hit_point == 0)
    {
        std::cout << "ClapTrap " << name << " can't do anything !" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage" << std::endl;
    energy_point--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " took " << amount << " points of damage" << std::endl;
    hit_point -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_point == 0 || hit_point == 0)
    {
        std::cout << "ClapTrap " << name << " can't do anything !" << std::endl;
        return;
    }
    std::cout << "Claptrap " << name << " repaired, and it gets" << amount << " hit points back" << std::endl;
    hit_point += amount;
    energy_point--;
}
