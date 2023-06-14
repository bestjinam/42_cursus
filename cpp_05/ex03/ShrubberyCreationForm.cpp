/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:54:08 by jinam             #+#    #+#             */
/*   Updated: 2023/06/14 16:43:28 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

const std::string ShrubberyCreationForm::SH_NAME = "ShrubberyCreationForm";

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", SH_SIGN, SH_EXEC)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", SH_SIGN, SH_EXEC), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
    : AForm(ref), _target(ref._target)
{
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
    {
        if (this != &ref)
        {
            this->~ShrubberyCreationForm();
            new (this) ShrubberyCreationForm(ref);
        }
        return *this;
    }
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    _checkExecuteGrade(executor);
	std::ofstream	fout;

    fout.open(_target + "_shrubbery");
    fout << "  *  \n"
              << " *** \n"
              << "**Y**\n"
              << "  |  \n";
    fout.close();
}
