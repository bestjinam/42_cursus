/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:27:26 by jinam             #+#    #+#             */
/*   Updated: 2023/06/08 17:43:52 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void _formMakingTest()
{
    Form f1;
    Form f2("new form 1", 150);
    Form f3("new form 2", 1);

    Form f4(f2);
    Form f5 = f3;

    std::cout << "f1's info(null)" << std::endl;
    std::cout << f1;
    std::cout << std::endl;
    std::cout << "f2's info(new form 1, 150)" << std::endl;
    std::cout << f2;
    std::cout << std::endl;
    std::cout << "f3's info(new form 2, 1)" << std::endl;
    std::cout << f3;
    std::cout << std::endl;
    std::cout << "======= copy ========" << std::endl;
    std::cout << std::endl;
    std::cout << "f4's info(copy)" << std::endl;
    std::cout << f4;
    std::cout << std::endl;
    std::cout << "f5's info(assignment operator)" << std::endl;
    std::cout << f5;
    std::cout << std::endl;
}

void _formMakingExceptionTest()
{
    Form f1("Lowest form", 151);
    Form f2("Highest form", 0);

    std::cout << f1;
}

void _formBeSignedTest()
{
    Form a("a", 1);
    Bureaucrat b("b", 1);

    std::cout << a;
    std::cout << std::endl;
    a.beSigned(b);
    std::cout << a;
}

void _formBesignedExceptionTest()
{
    Form a("a", 1);
    Bureaucrat b("b", 3);

    std::cout << a;
    std::cout << std::endl;
    a.beSigned(b);
    std::cout << a;
}

void _bureaucratSignFormTest()
{
    Form a("a", 5);
    Bureaucrat b("b", 3);

    b.signForm(a);
}

void _bureaucratSignFormExceptionTest()
{
    Form a("a", 1);
    Bureaucrat b("b", 3);

    b.signForm(a);
}
int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "./Bureaucrat [option]" << std::endl;
        return 1;
    }
    try
    {
        std::string str = argv[1];
        if (str.compare("0") == 0)
        {
            _formMakingTest();
        }
        else if (str.compare("1") == 0)
        {
            _formMakingExceptionTest();
        }
        else if (str.compare("2") == 0)
        {
            _formBeSignedTest();
        }
        else if (str.compare("3") == 0)
        {
            _formBesignedExceptionTest();
        }
        else if (str.compare("4") == 0)
        {
            _bureaucratSignFormTest();
        }
        else if (str.compare("5") == 0)
        {
            _bureaucratSignFormExceptionTest();
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
        return 1;
    }
    return 0;
}
