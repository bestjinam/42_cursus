/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:54:05 by jinam             #+#    #+#             */
/*   Updated: 2023/06/08 16:11:09 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
Bureaucrat::GradeTooLowException::GradeTooLowException(std::string _m)
    : _message("Grade too low:" + _m)
{
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return _message.c_str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string _m)
    : _message("Grade too high:" + _m)
{
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return _message.c_str();
}

Bureaucrat::Bureaucrat()
    : _name("null"), _grade(1)
{
}
Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name)
{
    _initGrade(grade);
}
Bureaucrat::Bureaucrat(std::string name)
    : _name(name)
{
    _initGrade(150);
}
void Bureaucrat::_initGrade(int grade)
{
    if (grade <= 0)
        throw GradeTooHighException(_name);
    else if (grade > 150)
        throw GradeTooLowException(_name);
    else
        _grade = grade;
}
Bureaucrat::~Bureaucrat()
{
}
Bureaucrat::Bureaucrat(const Bureaucrat& ref)
    : _name(ref._name)
{
    _initGrade(ref._grade);
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

std::string Bureaucrat::getName() const
{
    return _name;
}
void Bureaucrat::incrementGrade(int n)
{
    _initGrade(_grade - n);
}

void Bureaucrat::decrementGrade(int n)
{
    _initGrade(_grade + n);
}

void Bureaucrat::incrementGrade()
{
    _initGrade(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
    _initGrade(_grade + 1);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
    if (this != &ref)
    {
        this->~Bureaucrat();
        new (this) Bureaucrat(ref);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref)
{
    out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << "." << std::endl;
    return out;
}
