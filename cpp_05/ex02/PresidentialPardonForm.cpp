/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:44:42 by jinam             #+#    #+#             */
/*   Updated: 2023/06/14 10:47:42 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", PR_SIGN, PR_EXEC)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", PR_SIGN, PR_EXEC), _target(target)
{
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref)
    : AForm(ref), _target(ref._target)
{
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	{
        if (this != &ref)
        {
            this->~PresidentialPardonForm();
            new (this) PresidentialPardonForm(ref);
        }
        return *this;
    }
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    _checkExecuteGrade(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}