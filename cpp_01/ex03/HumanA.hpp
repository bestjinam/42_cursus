/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:31:09 by jinam             #+#    #+#             */
/*   Updated: 2023/04/18 15:53:40 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
private:
	Weapon		*weapon;
	std::string	name;
public:
	HumanA();
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack(void);
};

#endif
