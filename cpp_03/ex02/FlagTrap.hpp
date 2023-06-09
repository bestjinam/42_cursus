/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:34:44 by jinam             #+#    #+#             */
/*   Updated: 2023/04/29 14:53:15 by jinam            ###   ########.fr       */
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

#endif
