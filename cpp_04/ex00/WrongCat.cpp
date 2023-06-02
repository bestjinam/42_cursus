/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:13:57 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 14:16:25 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
    _type = WRONGCAT_TYPE;
    std::cout << _type << " default Constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << _type << " Destructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& ref)
{
    *this = ref;
    std::cout << _type << " copy Constructor called" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& ref)
{
    _type = ref._type;
    std::cout << _type << " assignment operator called" << std::endl;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Meow~😾" << std::endl;
}
