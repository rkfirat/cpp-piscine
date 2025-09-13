#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    Intern someRandomIntern;
    AForm* rrf;
    AForm* invalidForm;

    std::cout << "--- Başarılı Form Oluşturma Testi ---" << std::endl;
    try
    {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            Bureaucrat boss("Patron", 1);
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Hata: " << e.what() << '\n';
    }

    std::cout << "\n--- Hatalı Form Oluşturma Testi ---" << std::endl;
    try
    {
        invalidForm = someRandomIntern.makeForm("coffee request", "Stajyer");
        if (invalidForm)
            delete invalidForm;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Beklenen hata yakalandı: " << e.what() << '\n';
    }

}
