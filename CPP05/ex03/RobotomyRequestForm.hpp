#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string name);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;
    void beSigned(Bureaucrat &bureaucrat);
};
