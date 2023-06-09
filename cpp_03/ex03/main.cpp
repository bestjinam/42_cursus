/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:47:04 by jinam             #+#    #+#             */
/*   Updated: 2023/04/29 15:19:57 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    FlagTrap f1("Flag 1");
    ScavTrap s1("Scav 1");

    f1.showStats();
    f1.highFivesGuys();

    s1.showStats();
}
