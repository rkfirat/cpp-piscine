#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat recep("Recep", 10);
        Bureaucrat ahmet("Ahmet", 30);
        Bureaucrat mehmet("Mehmet", 100);

        Form rapor("ToplantiRaporu", 45, 30); 
        Form dilekce("Dilekce", 80, 50);        

        std::cout << "\n--- Senaryo 1: Recep imzalamaya calisiyor ---" << std::endl;
        recep.signForm(rapor);
        std::cout << rapor << std::endl;

        std::cout << "\n--- Senaryo 2: Ahmet imzaliyor ---" << std::endl;
        ahmet.signForm(rapor);
        std::cout << rapor << std::endl;

        std::cout << "\n--- Senaryo 3: Mehmet imzalamaya calisiyor ---" << std::endl;
        mehmet.signForm(dilekce);
        std::cout << dilekce << std::endl;

        std::cout << "\n--- Senaryo 4: Ahmet tekrar imzalamaya calisiyor ---" << std::endl;
        ahmet.signForm(rapor);
    }
    catch(const std::exception &e)
    {
        std::cerr << "✗ Exception: " << e.what() << std::endl;
    }

    return 0;
}