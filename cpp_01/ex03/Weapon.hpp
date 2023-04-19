/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:29:52 by jinam             #+#    #+#             */
/*   Updated: 2023/04/18 15:56:52 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_H
# define WEAPON_H
#include <string>

class Weapon
{
private:
		std::string type;
public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	void	setType(std::string type);
	const 	std::string	&getType(void);
};
#endif
