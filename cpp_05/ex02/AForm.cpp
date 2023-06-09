/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:58:33 by jinam             #+#    #+#             */
/*   Updated: 2023/06/09 16:23:37 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::GradeTooLowException::~GradeTooLowException() throw() {}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooLowException::GradeTooLowException(std::string _m)
    : _message("Form : Grade too low: " + _m)
{
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return _message.c_str();
}

AForm::GradeTooHighException::GradeTooHighException(std::string _m)
    : _message("Form : Grade too high: " + _m)
{
}
const char* AForm::GradeTooHighException::what() const throw()
{
    return _message.c_str();
}

AForm::AForm()
    : _name("null"), _require_grade(150), _sign(false)
{
}
AForm::AForm(std::string name, int grade)
    : _name(name), _require_grade(grade), _sign(false)
{
    _checkRequiredGrade(grade);
}

AForm::~AForm()
{
}
AForm::AForm(const AForm& ref)
    : _name(ref._name), _require_grade(ref._require_grade), _sign(false)
{
    _checkRequiredGrade(_require_grade);
}

void AForm::_checkRequiredGrade(int grade)
{
    if (grade <= 0)
        throw GradeTooHighException(_name);
    else if (grade > 150)
        throw GradeTooLowException(_name);
    else
        return;
}
void AForm::_checkExecuteGrade(Bureaucrat& bureau)
{
    const int grade = bureau.getGrade();

    if (grade > _require_grade)
        throw GradeTooLowException("Execute grade : " + _name);
    else
        return;
}

// getter
std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSign() const
{
    return _sign;
}

int AForm::getGrade() const
{
    return _require_grade;
}

void AForm::beSigned(Bureaucrat& human)
{
    const int grade = human.getGrade();

    if (grade > _require_grade)
        throw GradeTooLowException(_name);
    else
    {
        _sign = true;
    }
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "This Form's informations" << std::endl;
    out << "name : " << form.getName() << std::endl;
    out << "sign : " << form.getSign() << std::endl;
    out << "grade : " << form.getGrade() << std::endl;
    return out;
}
