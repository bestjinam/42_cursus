/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:05:47 by jinam             #+#    #+#             */
/*   Updated: 2023/06/14 16:52:13 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
    static const int PR_EXEC = 5;
    static const int PR_SIGN = 25;
public:
	static const std::string PR_NAME;
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& ref);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);
    virtual void execute(Bureaucrat const& executor) const;
};
#endif
