#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    Intern someRandomIntern;
    AForm* rrf = NULL;
    AForm* invalidForm;

    std::cout << "--- Başarılı Form Oluşturma Testi ---" << std::endl;
    try
    {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            Bureaucrat boss("Patron", 140);
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
            rrf = NULL;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Hata: " << e.what() << '\n';
        if (rrf)
            delete rrf;
        rrf = NULL;
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
