/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:53:51 by jinam             #+#    #+#             */
/*   Updated: 2023/06/13 22:11:37 by jinam            ###   ########.fr       */
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
    const int _signGrade;
    const int _execGrade;
    bool _sign;
    void _checkRequiredGrade(int grade);
    AForm& operator=(const AForm& ref);

public:
    AForm();
    AForm(std::string name, int grade);
    AForm(std::string name, int signGrade, int execGrade);
    virtual ~AForm();
    AForm(const AForm& ref);
    std::string getName() const;
    bool getSign() const;
    int getSignGrade() const;
    int getExecGrade() const;
    void beSigned(Bureaucrat& human);
    void _checkExecuteGrade(Bureaucrat const& bureau) const;
    virtual void execute(Bureaucrat const& executor) const = 0;

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
};

std::ostream& operator<<(std::ostream& out, const AForm& form);
#endif
