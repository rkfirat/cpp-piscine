#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    void signForm(Form &form);

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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);