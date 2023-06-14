/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:27:26 by jinam             #+#    #+#             */
/*   Updated: 2023/06/08 16:13:43 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void _getterTest(void)
{
    std::cout << "#1. Bureaucrat(a)" << std::endl;
    Bureaucrat a = Bureaucrat("a");
    std::cout << "name : " << a.getName() << std::endl;
    std::cout << "grade : " << a.getGrade() << std::endl;
    std::cout << "#2. Bureaucrat(b, 149)" << std::endl;
    std::cout << std::endl;
    Bureaucrat b = Bureaucrat("b", 149);
    std::cout << "name : " << b.getName() << std::endl;
    std::cout << "grade : " << b.getGrade() << std::endl;
}

void _constructAndPrintTest(void)
{
    try
    {
        Bureaucrat a("a", 3);
        Bureaucrat b(a);
        Bureaucrat c = a;

        std::cout << a;
        std::cout << b;
        std::cout << c;
    }
    catch (std::exception& ex)
    {
        std::exit(EXIT_FAILURE);
    }
}

void _tryCatchTest(void)
{
    Bureaucrat a("a", 151);
    Bureaucrat b("b", 0);

    std ::cout << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
}

int main(int argc, char** argv)
{
    try
    {
        if (argc != 2)
        {
            std::cout << "./Bureaucrat [option]" << std::endl;
            return 1;
        }
        std::string str = argv[1];

        if (str.compare("0") == 0)
            _getterTest();
        else if (str.compare("1") == 0)
            _constructAndPrintTest();
        else if (str.compare("2") == 0)
            _tryCatchTest();
        return 0;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
