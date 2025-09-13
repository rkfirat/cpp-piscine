#include "Form.hpp"

Form::Form() : name("Unnamed"), isSigned(false), execGrade(150), signGrade(150)
{

}

Form::Form(std::string name, int execGrade, int signGrade) : name(name),  isSigned(false), execGrade(execGrade), signGrade(signGrade)
{
    if (execGrade > 150)
    {
        throw Form::GradeTooLowException();
    }
    if (execGrade < 1)
    {
        throw Form::GradeTooHighException();
    }
    if (signGrade > 150)
    {
        throw Form::GradeTooLowException();
    }
    if (signGrade < 1)
    {
        throw Form::GradeTooHighException();
    }
}

Form::Form(const Form &other) : name(other.name)
{
    this->isSigned = other.isSigned;
    this->execGrade = other.execGrade;
    this->signGrade = other.signGrade;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
        this->execGrade = other.execGrade;
        this->signGrade = other.signGrade;
    }
    return *this;
}

Form::~Form()
{

}


std::string Form::getName() const
{
    return this->name;
}

bool Form::getSigned() const
{
    return this->isSigned;
}

int Form::getSignGrade() const
{
    return this->signGrade;
}

int Form::getExecGrade() const
{
    return this->execGrade;
}


void Form::beSigned(Bureaucrat &bureaucrat)
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

const char *Form::GradeTooHighException::what() const throw()
{
    return "Ulan bu işi yapacak seviyenin üstünde, daha yukarı çıkamazsın!";
}


const char *Form::GradeTooLowException::what() const throw()
{
    return "Haa haa, sen buraya giremezsin, grade’in yetmiyor.";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << form.getName() << ", form grade " << (form.getSigned() ? "signed" : "not signed") << ".";
    return out;
}