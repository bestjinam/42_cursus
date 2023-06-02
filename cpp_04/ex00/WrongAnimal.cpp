/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:19:40 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 14:05:35 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
    : _type("WrongAnimal")
{
    std::cout << "WrongAnimal default Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = ref;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    _type = ref._type;
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return (_type);
}

void WrongAnimal::setType(std::string t)
{
    _type = t;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound 🎵" << std::endl;
}
