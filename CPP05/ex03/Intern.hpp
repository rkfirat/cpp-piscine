#pragma once

#include <iostream>
class AForm;

class Intern
{
private:
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm *makeForm(std::string const &form_name, std::string const &target);

    class FormNotFoundException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};
