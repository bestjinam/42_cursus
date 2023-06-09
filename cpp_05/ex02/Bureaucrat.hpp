/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:30:22 by jinam             #+#    #+#             */
/*   Updated: 2023/06/08 21:59:16 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <ostream>
#include <string>

class AForm;
class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
    void _initGrade(int grade);
    // noncopyable
    // Bureaucrat& operator=(const Bureaucrat& ref);
    // Bureaucrat(const Bureaucrat& ref);

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
    Bureaucrat();
    Bureaucrat(std::string name);
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& ref);
    Bureaucrat& operator=(const Bureaucrat& ref);
    std::string getName() const;
    int getGrade() const;
    void decrementGrade(int n);
    void incrementGrade(int n);
    void decrementGrade();
    void incrementGrade();
    void signForm(AForm& form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bu);
#endif
