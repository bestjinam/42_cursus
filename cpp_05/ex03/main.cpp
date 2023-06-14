/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:27:26 by jinam             #+#    #+#             */
/*   Updated: 2023/06/14 17:55:12 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <iostream>

void ft_exit(void)
{
    system("leaks Bureaucrat");
}

int main()
{
    atexit(ft_exit);
    std::string _names[3] = {ShrubberyCreationForm::SH_NAME,
                             RobotomyRequestForm::RO_NAME,
                             PresidentialPardonForm::PR_NAME};
    Intern somRandomIntern;
    Bureaucrat b1("b1", 1);
    AForm* rrf;

    for (int i = 0; i != 3; i++)
    {
        rrf = somRandomIntern.makeForm(_names[i], "test0");
        b1.executeForm(*rrf);
        std::cout << std::endl;
        delete rrf;
    }
    return 0;
}
