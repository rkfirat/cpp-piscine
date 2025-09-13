#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("RobotomyRequestForm", 45, 72)
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string name) : AForm(name, 45, 72)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        this->execGrade = other.execGrade;
        this->signGrade = other.execGrade;
        this->isSigned = other.isSigned;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}


void PresidentialPardonForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getSignGrade())
    {
        if (!isSigned)
        {
            isSigned = true;
            std::cout << bureaucrat.getName()
                      << " abi formu imzaladı, artık resmi olarak tamam!"
                      << std::endl;
        }
        else
        {
            std::cout << bureaucrat.getName()
                      << " abi formu zaten imzalamış, tekrar deneme ha 😏"
                      << std::endl;
        }
    }
    else
    {
        std::cout << bureaucrat.getName()
                  << " abi grade’in yetmedi, formu imzalayamazsın 😅"
                  << std::endl;
        throw GradeTooLowException();
    }
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned)
    {
        throw GradeTooLowException();
    }
    if (executor.getGrade() > this->execGrade)
    {
        throw GradeTooLowException();
    }

    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}