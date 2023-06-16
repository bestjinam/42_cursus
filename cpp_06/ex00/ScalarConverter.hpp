/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:41:43 by jinam             #+#    #+#             */
/*   Updated: 2023/06/16 22:40:47 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& ref);
    ScalarConverter& operator=(const ScalarConverter& ref);
    ~ScalarConverter();

public:
    static void convert(std::string str);
};

#endif
