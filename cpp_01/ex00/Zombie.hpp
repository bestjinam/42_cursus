/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:33:09 by jinam             #+#    #+#             */
/*   Updated: 2023/04/16 15:59:07 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>


class Zombie
{
private:
    std::string name;
    Zombie(const Zombie& ref);
public:
    Zombie(std::string n);
    ~Zombie();
    Zombie& operator=(const Zombie& ref);
    void    announce(void);
};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);
#endif
