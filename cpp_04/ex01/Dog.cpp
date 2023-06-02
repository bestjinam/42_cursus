/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:19:21 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 19:02:22 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog()
{
    _brain = new Brain();
    _type = DOG_TYPE;
    std::cout << _type << " default Constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << _type << " Destructor called" << std::endl;
    delete _brain;
}
Dog::Dog(const Dog& ref)
{
    _brain = NULL;
    *this = ref;
    std::cout << _type << " copy Constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& ref)
{
    _type = ref._type;
    delete _brain;
    _brain = new Brain();
    *_brain = *ref._brain;
    std::cout << _type << " assignment operator called" << std::endl;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Bark ~ 🐶" << std::endl;
}

std::string Dog::getIdea(int idx)
{
    return (_brain->getIdea(idx));
}

void Dog::setIdea(std::string think)
{
    _brain->setIdea(think);
}

Brain& Dog::getBrain()
{
    return (*_brain);
}
