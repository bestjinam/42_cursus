/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:27:26 by jinam             #+#    #+#             */
/*   Updated: 2023/06/14 16:19:39 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void _formExecuteTest(AForm &form)
{
    Bureaucrat b1("b1", 1);

    std::cout << ">>_formMakingTest <<\n";
    std::cout << b1 << std::endl;
    std::cout << form;
    form.execute(b1);

}

void _formMakingExceptionTest(AForm &form)
{
    Bureaucrat b1("b1", 150);

    std::cout << ">>_formMakingExceptionTest <<\n";
    std::cout << b1 << std::endl;
    std::cout << form << std::endl;
    form.execute(b1);
}

void _bureaucratSignFormTest(AForm &form)
{
    std::cout << ">>_bureaucratSignFormTest <<\n";
    Bureaucrat b1("b1", 1);
    b1.signForm(form);
    std::cout << form <<std::endl;
}

void _bureaucratExecuteFormTest(AForm &form)
{
    std::cout << ">>_bureaucratExecuteFormTest <<\n";
    Bureaucrat b1("b1", 1);
    b1.executeForm(form);
}

void _bureaucratExecuteFormExceptionTest(AForm &form)
{
    std::cout << ">>_bureaucratExecuteFormExceptionTest <<\n";
    Bureaucrat b1("b1", 150);
    b1.executeForm(form);
}

void    ft_exit(void)
{
    system("leaks Bureaucrat");
}

int main()
{
    AForm *forms[3];

    forms[0] = new ShrubberyCreationForm("Target1");
    forms[1] = new RobotomyRequestForm("Target2");
    forms[2] = new PresidentialPardonForm("Target3");
    std::string str;
    atexit(ft_exit);
    int ret = 0;
    try
    {
        for (int i = 0; i != 3; i++)
        {
            std:: cout << i << std::endl;
            std::cout << "Press Enter ...\n";
            std::getline(std::cin, str); 
            _formExecuteTest(*forms[i]);
            std::cout << std::endl;
            _bureaucratSignFormTest(*forms[i]);
            std::cout << std::endl;
            _bureaucratExecuteFormTest(*forms[i]);
            // _formMakingExceptionTest(*forms[i]);
            // std::cout << std::endl;
        }
        std::cout << "press e button..\n";
        std::getline(std::cin, str); 
        if (str.compare("e") == 0)
        {
            // _formMakingExceptionTest(*forms[0]);
            _bureaucratExecuteFormExceptionTest(*forms[0]);
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
        ret = 1;
    }
    delete forms[0];
    delete forms[1];
    delete forms[2];
    return ret;
}
