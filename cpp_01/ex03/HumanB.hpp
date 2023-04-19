/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:31:09 by jinam             #+#    #+#             */
/*   Updated: 2023/04/18 16:02:33 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
private:
	Weapon		*weapon;
	std::string	name;
public:
	HumanB();
	HumanB(std::string name);
	~HumanB();
	void	attack(void);
	void	setWeapon(Weapon &weapon);
};

#endif
