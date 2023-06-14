/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:47:49 by jinam             #+#    #+#             */
/*   Updated: 2023/06/14 17:42:48 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}
Intern::Intern(const Intern& ref)
{
    (void) ref;
}
Intern& Intern::operator=(const Intern& ref)
{
    (void) ref;
    return *this;
}
AForm* Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string _names[3] = {ShrubberyCreationForm::SH_NAME,
                             RobotomyRequestForm::RO_NAME,
                             PresidentialPardonForm::PR_NAME};
    AForm   *res;
    int	i = 0;
    while (i != 3)
    {
    	if (name.compare(_names[i]) == 0)
    		break ;
    	i ++;
    }
    switch (i)
    {
        case SHRUBBERY:
            res = new ShrubberyCreationForm(target);
            break ;
        case ROBOTOMY:
            res = new RobotomyRequestForm(target);
            break ;
        case PRESIDENTIAL:
            res = new PresidentialPardonForm(target);
            break ;
        default:
            res = NULL;
    }
    if (res)
        std::cout << "Intern creates " ;
    else
        std::cout << "Intern could'nt create form : ";
    std::cout << name << std::endl;
    return res;
}
