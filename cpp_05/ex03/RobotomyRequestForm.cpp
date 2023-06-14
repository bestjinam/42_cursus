/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:39:12 by jinam             #+#    #+#             */
/*   Updated: 2023/06/14 17:53:43 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


const std::string RobotomyRequestForm::RO_NAME = "RobotomyRequestForm";

RobotomyRequestForm::RobotomyRequestForm()
	: AForm(RO_NAME, RO_SIGN, RO_EXEC)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm(RO_NAME, RO_SIGN, RO_EXEC), _target(target)
{
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
    : AForm(ref), _target(ref._target)
{
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	{
        if (this != &ref)
        {
            this->~RobotomyRequestForm();
            new (this) RobotomyRequestForm(ref);
        }
        return *this;
    }

}
void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	unsigned int	r_num;
	unsigned int	res;

    _checkExecuteGrade(executor);
	std::srand((unsigned int) time(NULL));
	r_num = rand();
	res = (rand() * 2147483657 + 4242) % 2;
	if (res)
		std::cout << "DRRRRRRIIILLLLL : " << _target << " has been robotomized!" << std::endl;
	else
		std::cout << "ROBOTOMY FAILED : " << _target << std::endl;
}
