#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade = grade;
    this->name = name;
}


Bureaucrat::Bureaucrat(const Bureaucrat &other)
{

        this->name = other.name;
        this->grade = other.grade;

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Abiii sen zaten patronun patronusun, daha yukari cikamazsin!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Kardes kusura bakma ama sen caylak bile olamazsin, bu kapidan gecemezsin.";
}


void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    grade--;
}
void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    grade++;
}

void Bureaucrat::signForm(Form &form)
{
    if (grade <= form.getSignGrade())
    {
        if (!form.getSigned())
        {
            form.beSigned(*this);
            std::cout << name << " abi formu imzaladı, artık resmi olarak tamam!" << std::endl;
        }
        else
        {
            std::cout << name << " abi formu zaten imzalamış, tekrar deneme ha 😏" << std::endl;
        }
    } 
    else
    {
        std::cout << name << " abi grade’in yetmedi, formu imzalayamazsın 😅" << std::endl;
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}