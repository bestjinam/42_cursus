/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:53:51 by jinam             #+#    #+#             */
/*   Updated: 2023/06/08 16:09:43 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
class Bureaucrat;
class Form
{
private:
    const std::string _name;
    const int _require_grade;
    bool _sign;
    void _checkRequiredGrade(int grade);

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

    Form();
    Form(std::string name, int grade);
    ~Form();
    Form(const Form& ref);
    Form& operator=(const Form& ref);
    std::string getName() const;
    bool getSign() const;
    int getGrade() const;
    void beSigned(Bureaucrat& human);
};

std::ostream& operator<<(std::ostream& out, const Form& form);
#endif
