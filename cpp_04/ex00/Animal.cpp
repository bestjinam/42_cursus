/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:19:40 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 13:59:34 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
    : _type("Animal")
{
    std::cout << "Animal default Constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal& ref)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = ref;
}

Animal& Animal::operator=(const Animal& ref)
{
    std::cout << "Animal assignment operator called" << std::endl;
    _type = ref._type;
    return (*this);
}

std::string Animal::getType() const
{
    return (_type);
}

void Animal::setType(std::string t)
{
    _type = t;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound 🎵" << std::endl;
}
