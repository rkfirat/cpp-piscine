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

AForm *Intern::makeShrubbery(const std::string target)
{
    return new ShrubberyCreationForm(target);
}
AForm *Intern::makeRobotomy(const std::string target)
{
    return new RobotomyRequestForm(target);
}
AForm *Intern::makePresidential(const std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const & form_name, std::string const & target)
{
    AForm* newForm = NULL;

    std::string levels[] = {"shrubbery creation", "robotomy request", "presidental pardon"};
    int id = -1;

    for (int i = 0; i < 3; ++i)
    {
        if (levels[i] == form_name)
        {
            id = i;
            break;
        }
    }

    switch (id)
    {
    case 0:
        newForm = makeShrubbery(target);
        break;
    case 1:
        newForm = makeRobotomy(target);
        break;
    case 2:
        newForm = makePresidential(target);
        break;
    default:
        throw Intern::FormNotFoundException();
        break;
    }
    std::cout << "Intern creates " << form_name << std::endl;
    return newForm; 
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Stajyer öyle bir form bilmiyor, kahve getirmesini falan mı isteseydin?";
}