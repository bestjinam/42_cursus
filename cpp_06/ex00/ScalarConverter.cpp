/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:57:34 by jinam             #+#    #+#             */
/*   Updated: 2023/06/16 22:40:58 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter& ref)
{
    (void)ref;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref)
{
    (void)ref;
    return *this;
}

void ScalarConverter::convert(std::string str)
{
    (void)str;
    std::cout << " TEST\n";
}
