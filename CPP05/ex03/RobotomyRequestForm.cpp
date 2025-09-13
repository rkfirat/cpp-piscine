#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 45, 72)
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string name) : AForm(name, 45, 72)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        this->execGrade = other.execGrade;
        this->signGrade = other.execGrade;
        this->isSigned = other.isSigned;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}


void RobotomyRequestForm::beSigned(Bureaucrat &bureaucrat)
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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned)
    {
        throw GradeTooLowException();
    }
    if (executor.getGrade() > this->execGrade)
    {
        throw GradeTooLowException();
    }

    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(0));
        seeded = true;
    }

    std::cout << "Bzzzzzz... drilling noises..." << std::endl;
    if (std::rand() % 2)
        std::cout << this->name << " has been robotomized successfully!" << std::endl;
    else
        std::cout << this->name << " robotomy failed!" << std::endl;
}