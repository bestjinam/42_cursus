/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:14:04 by jinam             #+#    #+#             */
/*   Updated: 2023/04/19 20:49:38 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>


class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void); void	error(void); public:
	Harl();
	~Harl();
	void	complain(std::string level);
};

typedef void	(Harl::*fptr)();

#endif
