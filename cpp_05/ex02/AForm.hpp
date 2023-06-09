/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:53:51 by jinam             #+#    #+#             */
/*   Updated: 2023/06/09 16:20:38 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
class Bureaucrat;
class AForm
{
private:
    const std::string _name;
    const int _require_grade;
    bool _sign;
    void _checkRequiredGrade(int grade);
    void _checkExecuteGrade(Bureaucrat& bureau);
    AForm& operator=(const AForm& ref);

public:
    class GradeTooHighException : public std::exception
    {
    private:
        std::string _message;

    public:
        virtual ~GradeTooHighException() throw();
        GradeTooHighException(std::string _m);
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    private:
        std::string _message;

    public:
        virtual ~GradeTooLowException() throw();
        GradeTooLowException(std::string _m);
        virtual const char* what() const throw();
    };

    AForm();
    AForm(std::string name, int grade);
    virtual ~AForm();
    AForm(const AForm& ref);
    std::string getName() const;
    bool getSign() const;
    int getGrade() const;
    void beSigned(Bureaucrat& human);
    virtual void excute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);
#endif
