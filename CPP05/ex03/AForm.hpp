#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
    const       std::string name;
    bool        isSigned;
    int         execGrade;
    int         signGrade;

public:
    AForm();
    AForm(std::string name, int execGrade, int signGrade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();
    
    std::string getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    virtual void beSigned(Bureaucrat &bureaucrat);

    virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream& out, const AForm& Aform);