/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:51:04 by jinam             #+#    #+#             */
/*   Updated: 2023/06/04 01:32:12 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
Brain::Brain()
{
    std::cout << " Brain default Constructor called" << std::endl;
    _len = 0;
}

Brain::~Brain()
{
    std::cout << " Brain destructor called" << std::endl;
}
Brain::Brain(const Brain& ref)
{
    std::cout << " Brain copy Constructor called" << std::endl;
    *this = ref;
}
Brain& Brain::operator=(const Brain& ref)
{
    std::cout << " Brain copy assignment operator called" << std::endl;
    for (int i = 0; i != ref._len + 1; i++)
    {
        _ideas[i] = ref._ideas[i];
    }
    return (*this);
}

std::string Brain::getIdea(int idx)
{
    if (idx < _len)
        return (_ideas[idx]);
    else
        return "";
}

void Brain::setIdea(std::string think)
{
    if (_len == 100)
        _len = 0;
    _ideas[_len] = think;
    _len++;
}
