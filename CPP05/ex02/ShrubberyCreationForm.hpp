#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string name);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor) const;
    void beSigned(Bureaucrat &bureaucrat);
};
