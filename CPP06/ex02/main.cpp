#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generate(void)
{
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(0));
        seeded = true;
    }
    int choice = std::rand() % 3;
    if (choice == 0)
        return new A();
    else if (choice == 1)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
    }

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
    }

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
    }
}

int main()
{
    std::cout << "--- Test 1 ---" << std::endl;
    Base *p1 = generate();
    std::cout << "identify(pointer):   ";
    identify(p1);
    std::cout << "identify(reference): ";
    identify(*p1);
    delete p1;

    std::cout << "\n--- Test 2 ---" << std::endl;
    Base *p2 = generate();
    std::cout << "identify(pointer):   ";
    identify(p2);
    std::cout << "identify(reference): ";
    identify(*p2);
    delete p2;

    std::cout << "\n--- Test 3 ---" << std::endl;
    Base *p3 = generate();
    std::cout << "identify(pointer):   ";
    identify(p3);
    std::cout << "identify(reference): ";
    identify(*p3);
    delete p3;

    return 0;
}