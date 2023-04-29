/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:47:04 by jinam             #+#    #+#             */
/*   Updated: 2023/04/27 17:38:53 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap a("a");
    ClapTrap b("b");
    ClapTrap d("c_copy");
    ClapTrap c(d);

    std::cout << "----- a attacks b -----" << std::endl;
    a.attack("b");
    std::cout << "----- c attacks b -----" << std::endl;
    c.attack("b");
    std::cout << "----- b takes 10 damages -" << std::endl;
    b.takeDamage(10);

    std::cout << "----- b attempts to do something -" << std::endl;
    b.attack("a");
    b.beRepaired(10);
    std::cout << "----- a takes 5 damages -" << std::endl;
    b.takeDamage(5);
    std::cout << "----- a repair 10 times-" << std::endl;
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
}
