/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:58:33 by jinam             #+#    #+#             */
/*   Updated: 2023/06/08 16:53:00 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::GradeTooLowException::~GradeTooLowException() throw() {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::GradeTooLowException(std::string _m)
    : _message("Form : Grade too low: " + _m)
{
}
const char* Form::GradeTooLowException::what() const throw()
{
    return _message.c_str();
}

Form::GradeTooHighException::GradeTooHighException(std::string _m)
    : _message("Form : Grade too high: " + _m)
{
}
const char* Form::GradeTooHighException::what() const throw()
{
    return _message.c_str();
}

Form::Form()
    : _name("null"), _require_grade(150), _sign(false)
{
}
Form::Form(std::string name, int grade)
    : _name(name), _require_grade(grade), _sign(false)
{
    _checkRequiredGrade(grade);
}

Form::~Form()
{
}
Form::Form(const Form& ref)
    : _name(ref._name), _require_grade(ref._require_grade), _sign(false)
{
    _checkRequiredGrade(_require_grade);
}
Form& Form::operator=(const Form& ref)

{
    if (this != &ref)
    {
        this->~Form();
        new (this) Form(ref);
    }
    return *this;
}

void Form::_checkRequiredGrade(int grade)
{
    if (grade <= 0)
        throw GradeTooHighException(_name);
    else if (grade > 150)
        throw GradeTooLowException(_name);
    else
        return;
}
// getter
std::string Form::getName() const
{
    return _name;
}

bool Form::getSign() const
{
    return _sign;
}

int Form::getGrade() const
{
    return _require_grade;
}

void Form::beSigned(Bureaucrat& human)
{
    const int grade = human.getGrade();

    if (grade > _require_grade)
        throw GradeTooLowException(_name);
    else
    {
        _sign = true;
    }
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "This Form's informations" << std::endl;
    out << "name : " << form.getName() << std::endl;
    out << "sign : " << form.getSign() << std::endl;
    out << "grade : " << form.getGrade() << std::endl;
    return out;
}
