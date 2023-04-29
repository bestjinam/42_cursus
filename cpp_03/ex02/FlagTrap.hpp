/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:34:44 by jinam             #+#    #+#             */
/*   Updated: 2023/04/27 19:46:23 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP
#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap
{
private:
public:
    FlagTrap();
    FlagTrap(std::string name);
    ~FlagTrap();
    FlagTrap(const FlagTrap& ref);
    FlagTrap& operator=(const FlagTrap& ref);
    void highFivesGuys(void);
};

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
              << "default constructor called" << std::endl;
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
#endif
