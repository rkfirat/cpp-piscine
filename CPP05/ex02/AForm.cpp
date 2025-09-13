#include "AForm.hpp"

AForm::AForm() : name("Unnamed"), isSigned(false), execGrade(150), signGrade(150)
{
}

AForm::AForm(std::string name, int execGrade, int signGrade) : name(name), isSigned(false), execGrade(execGrade), signGrade(signGrade)
{
    if (execGrade > 150)
    {
        throw AForm::GradeTooLowException();
    }
    if (execGrade < 1)
    {
        throw AForm::GradeTooHighException();
    }
    if (signGrade > 150)
    {
        throw AForm::GradeTooLowException();
    }
    if (signGrade < 1)
    {
        throw AForm::GradeTooHighException();
    }
}

AForm::AForm(const AForm &other) : name(other.name)
{
    this->isSigned = other.isSigned;
    this->execGrade = other.execGrade;
    this->signGrade = other.signGrade;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
        this->execGrade = other.execGrade;
        this->signGrade = other.signGrade;
    }
    return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getSigned() const
{
    return this->isSigned;
}

int AForm::getSignGrade() const
{
    return this->signGrade;
}

int AForm::getExecGrade() const
{
    return this->execGrade;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
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

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Ulan bu işi yapacak seviyenin üstünde, daha yukarı çıkamazsın!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Haa haa, sen buraya giremezsin, grade’in yetmiyor.";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << form.getName() << ", form grade " << (form.getSigned() ? "signed" : "not signed") << ".";
    return out;
}