#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 137, 145)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : AForm(name, 137, 145)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        this->execGrade = other.execGrade;
        this->signGrade = other.execGrade;
        this->isSigned = other.isSigned;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}


void ShrubberyCreationForm::beSigned(Bureaucrat &bureaucrat)
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

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned)
    {
        throw GradeTooLowException();
    }
    if (executor.getGrade() > this->execGrade)
    {
        throw GradeTooLowException();
    }
	std::string newfile = executor.getName() + "_shrubbery";
	std::ofstream outFile(newfile.c_str());
	if (!outFile)
        std::cerr << "output file can't be created" << std::endl;
	outFile <<
	"      ccee88oo\n"
	"   C8O8O8Q8PoOb o8oo\n"
	"  dOB69QO8PdUOpugoO9bD\n"
	" CgggbU8OU qOp qOdoUOdcb\n"
	"    6OuU  /p u gcoUodpP\n"
	"      \\\\//  /douUP\n"
	"        \\\\////\n"
	"         |||/\\\n"
	"         |||\\/\n"
	"         |||||\n"
	"   .....//||||\\....\n";
}