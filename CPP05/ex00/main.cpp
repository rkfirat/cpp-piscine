#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        std::cout << "[TEST] " << "Bureaucrat(Erman, 150)" << std::endl;
        Bureaucrat b1("Erman", 150);
        std::cout << "✓ Başarılı: " << b1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "✗ Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "[TEST] " << "Bureaucrat(Ahmet, 1)" << std::endl;
        Bureaucrat b2("Ahmet", 1);
        std::cout << "✓ Başarılı: " << b2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "✗ Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "[TEST] " << "Bureaucrat(Mehmet, 151)" << std::endl;
        Bureaucrat b3("Mehmet", 151);
        std::cout << "✓ Başarılı: " << b3 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "✗ Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "[TEST] " << "Bureaucrat(Ayşe, 0)" << std::endl;
        Bureaucrat b4("Ayşe", 0);
        std::cout << "✓ Başarılı: " << b4 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "✗ Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "[TEST] Increment Grade (Ahmet, 1)" << std::endl;
        Bureaucrat b5("Ahmet", 1);
        std::cout << "Başlangıç grade = " << b5 << std::endl;
        b5.incrementGrade();
        std::cout << "Son grade = " << b5 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "[TEST] Decrement Grade (Erman, 150)" << std::endl;
        Bureaucrat b6("Erman", 150);
        std::cout << "Başlangıç = " << b6 << std::endl;
        b6.decrementGrade();
        std::cout << "Son grade = " << b6 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
