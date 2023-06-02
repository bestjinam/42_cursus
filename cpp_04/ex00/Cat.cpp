/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:13:57 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 12:47:27 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    _type = CAT_TYPE;
    std::cout << _type << " default Constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << _type << " Destructor called" << std::endl;
}
Cat::Cat(const Cat& ref)
{
    *this = ref;
    std::cout << _type << " copy Constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat& ref)
{
    _type = ref._type;
    std::cout << _type << " assignment operator called" << std::endl;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow~😾" << std::endl;
}
