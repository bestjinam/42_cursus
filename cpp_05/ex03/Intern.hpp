/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:44:28 by jinam             #+#    #+#             */
/*   Updated: 2023/06/14 17:26:51 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
#include <string>
class AForm;
class Intern
{
	enum forms
	{
		SHRUBBERY = 0,
		ROBOTOMY,
		PRESIDENTIAL,
	};
private:
	

public:
	Intern();
	~Intern();
	Intern(const Intern& ref);
	Intern& operator=(const Intern& ref);
	AForm *makeForm(const std::string &name, const std::string &target);
};

#endif
