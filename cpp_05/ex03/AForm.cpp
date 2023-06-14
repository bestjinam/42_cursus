/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:58:33 by jinam             #+#    #+#             */
/*   Updated: 2023/06/13 22:11:42 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
AForm::AForm()
    : _name("null"), _signGrade(150), _execGrade(150), _sign(false)
{
}
AForm::AForm(std::string name, int grade)
    : _name(name), _signGrade(grade), _execGrade(150), _sign(false)
{
    _checkRequiredGrade(grade);
}
AForm::AForm(std::string name, int signGrade, int execGrade)
    : _name(name), _signGrade(signGrade), _execGrade(execGrade), _sign(false)
{
}

AForm::~AForm()
{
}
AForm::AForm(const AForm& ref)
    : _name(ref._name), _signGrade(ref._signGrade), _execGrade(ref._execGrade), _sign(ref._sign)
{
    _checkRequiredGrade(_signGrade);
    _checkRequiredGrade(_execGrade);
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
void AForm::_checkExecuteGrade(Bureaucrat const& bureau) const
{
    const int grade = bureau.getGrade();

    if (grade > _execGrade)
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

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecGrade() const
{
    return _execGrade;
}
void AForm::beSigned(Bureaucrat& human)
{
    const int grade = human.getGrade();

    if (grade > _signGrade)
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
    out << "signgrade : " << form.getSignGrade() << std::endl;
    out << "execgrade : " << form.getExecGrade() << std::endl;
    return out;
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooLowException::GradeTooLowException(std::string _m)
    : _message("AForm : Grade too low: " + _m)
{
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return _message.c_str();
}

AForm::GradeTooHighException::GradeTooHighException(std::string _m)
    : _message("AForm : Grade too high: " + _m)
{
}
const char* AForm::GradeTooHighException::what() const throw()
{
    return _message.c_str();
}
