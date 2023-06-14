/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:38:51 by jinam             #+#    #+#             */
/*   Updated: 2023/06/13 23:32:26 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
    static const int SH_EXEC = 137;
    static const int SH_SIGN = 145;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& ref);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);
    virtual void execute(Bureaucrat const& executor) const;
};

#endif
