/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:47:04 by jinam             #+#    #+#             */
/*   Updated: 2023/04/27 19:09:58 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    ScavTrap a("a");
    ScavTrap b("b");

    a.attack("b");
    //((ClapTrap)a).attack("b");
    b.takeDamage(10);
    a.guardGate();
}
