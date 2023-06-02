/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:13:57 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 19:01:48 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat()
{
    _brain = new Brain();
    _type = CAT_TYPE;
    std::cout << _type << " default Constructor called" << std::endl;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << _type << " Destructor called" << std::endl;
}
Cat::Cat(const Cat& ref)
{
    _brain = NULL;
    *this = ref;
    std::cout << _type << " copy Constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat& ref)
{
    std::cout << _type << " assignment operator called" << std::endl;
    _type = ref._type;
    delete _brain;
    _brain = new Brain();
    *_brain = *ref._brain;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow~😾" << std::endl;
}

std::string Cat::getIdea(int idx)
{
    return (_brain->getIdea(idx));
}

void Cat::setIdea(std::string think)
{
    _brain->setIdea(think);
}

Brain& Cat::getBrain()
{
    return (*_brain);
}
