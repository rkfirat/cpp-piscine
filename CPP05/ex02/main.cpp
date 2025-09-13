#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    ShrubberyCreationForm   shrubForm("garden");
    RobotomyRequestForm     roboForm("Bender");
    PresidentialPardonForm  pardonForm("Arthur Dent");

    try
    {
        Bureaucrat boss("Patron", 1);
        std::cout << boss << std::endl;

        std::cout << "\n--- Shrubbery Form Testi ---" << std::endl;
        boss.signForm(shrubForm);
        boss.executeForm(shrubForm);

        std::cout << "\n--- Robotomy Form Testi ---" << std::endl;
        boss.signForm(roboForm);
        boss.executeForm(roboForm);
        boss.executeForm(roboForm);

        std::cout << "\n--- Presidential Pardon Form Testi ---" << std::endl;
        boss.signForm(pardonForm);
        boss.executeForm(pardonForm);
    }
    catch (std::exception &e)
    {
        std::cerr << "Beklenmedik Hata: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat intern("Stajyer", 150);
        std::cout << intern << std::endl;

        std::cout << "\n--- İmza için yetersiz rütbe testi ---" << std::endl;
        intern.signForm(shrubForm);
    }
    catch (std::exception &e)
    {
        std::cerr << "Beklenen Hata Yakalandı: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat middleMan("Orta Kademe Yönetici", 40);
        std::cout << middleMan << std::endl;

        std::cout << "\n--- Yürütme için yetersiz rütbe testi (imza da başarısız) ---" << std::endl;
        middleMan.signForm(pardonForm);
        middleMan.executeForm(pardonForm);
    }
    catch (std::exception &e)
    {
        std::cerr << "Beklenen Hata Yakalandı: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat boss("Patron", 1);
        RobotomyRequestForm unsignedForm("Wall-E");
        std::cout << boss << std::endl;

        std::cout << "\n--- İmzasız formu yürütme testi ---" << std::endl;
        boss.executeForm(unsignedForm);
    }
    catch (std::exception &e)
    {
        std::cerr << "Beklenen Hata Yakalandı: " << e.what() << std::endl;
    }

}
