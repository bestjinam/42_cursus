/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:11:42 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 14:13:53 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
    std::string _type;

public:
    Animal();
    virtual ~Animal();
    Animal(const Animal& ref);
    Animal& operator=(const Animal& ref);
    virtual void makeSound(void) const;
    void setType(std::string t);
    std::string getType(void) const;
};
#endif
