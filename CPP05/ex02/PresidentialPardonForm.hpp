#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string name);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor) const;
    void beSigned(Bureaucrat &bureaucrat);
};
