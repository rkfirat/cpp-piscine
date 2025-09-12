#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string name;
    bool        isSigned;
    int         execGrade;
    int         signGrade;

public:
    Form();
    Form(std::string name, int execGrade, int signGrade);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();
    
    std::string getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
    {
    private:
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    private:
    public:
        virtual const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& form);