/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:19:21 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 12:47:32 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    _type = DOG_TYPE;
    std::cout << _type << " default Constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << _type << " Destructor called" << std::endl;
}
Dog::Dog(const Dog& ref)
{
    *this = ref;
    std::cout << _type << " copy Constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& ref)
{
    _type = ref._type;
    std::cout << _type << " assignment operator called" << std::endl;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Bark ~ 🐶" << std::endl;
}
