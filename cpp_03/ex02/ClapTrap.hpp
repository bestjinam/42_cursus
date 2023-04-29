/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:16:37 by jinam             #+#    #+#             */
/*   Updated: 2023/04/27 18:37:14 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
class ClapTrap
{
protected:
    std::string name;
    int hit_point;
    int energy_point;
    int attack_damage;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(std::string n, int h, int energy, int attack);
    ~ClapTrap();
    ClapTrap(const ClapTrap& ref);
    ClapTrap& operator=(const ClapTrap& ref);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
