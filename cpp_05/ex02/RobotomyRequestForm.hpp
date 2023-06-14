/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:31:31 by jinam             #+#    #+#             */
/*   Updated: 2023/06/14 16:09:31 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
	static const std::string RO_NAME;
    static const int RO_EXEC = 45;
    static const int RO_SIGN = 72;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string	target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& ref);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
    virtual void execute(Bureaucrat const& executor) const;
};
#endif
