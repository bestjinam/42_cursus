/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:58:50 by jinam             #+#    #+#             */
/*   Updated: 2023/04/16 21:59:42 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*res;

	res = new Zombie [N];
	for (int i = 0; i != N; i ++)
	{
		res[i].setName(name + std::to_string(i));
	}
	return (res);
}
