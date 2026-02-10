#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
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
}


Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
    this->grade = other.grade;

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
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
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}

void Bureaucrat::executeForm(AForm const & form) const
{
    form.execute(*this);
}

void Bureaucrat::signForm(AForm &form)
{
    form.beSigned(*this);
}