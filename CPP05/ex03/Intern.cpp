#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{

}

AForm* Intern::makeForm(std::string const & form_name, std::string const & target)
{
    AForm* newForm = NULL;

    if (form_name == "shrubbery creation")
        newForm = new ShrubberyCreationForm(target);
    else if (form_name == "robotomy request")
        newForm = new RobotomyRequestForm(target);
    else if (form_name == "presidential pardon")
        newForm = new PresidentialPardonForm(target);

    if (newForm)
    {
        std::cout << "Intern creates " << form_name << std::endl;
        return newForm;
    }
    
    throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Stajyer öyle bir form bilmiyor, kahve getirmesini falan mı isteseydin?";
}