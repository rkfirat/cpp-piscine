#include "Array.hpp"
#include <iostream>

int main(void)
{
    try
    {
        std::cout << "Empty array test\n";
        Array<int> empty;
        std::cout << "size(): " << empty.getSize() << "\n";
        try
        {
            std::cout << "access empty[0]: ";
            std::cout << empty[0] << "\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "caught: " << e.what() << "\n";
        }

        std::cout << "\nInteger array test\n";
        Array<int> a(5);
        for (unsigned int i = 0; i < a.getSize(); ++i)
            a[i] = i * 10;
        std::cout << "a: ";
        for (unsigned int i = 0; i < a.getSize(); ++i)
            std::cout << a[i] << " ";
        std::cout << "\n";

        Array<int> b(a); // copy ctor
        a[0] = 999;
        std::cout << "after a[0]=999 -> a: ";
        for (unsigned int i = 0; i < a.getSize(); ++i)
            std::cout << a[i] << " ";
        std::cout << "\n";
        std::cout << "copy b (should keep original values): ";
        for (unsigned int i = 0; i < b.getSize(); ++i)
            std::cout << b[i] << " ";
        std::cout << "\n";

        Array<int> c;
        c = a; // assignment
        c[1] = 111;
        std::cout << "after c = a and c[1]=111 -> a: ";
        for (unsigned int i = 0; i < a.getSize(); ++i)
            std::cout << a[i] << " ";
        std::cout << "\n";
        std::cout << "c: ";
        for (unsigned int i = 0; i < c.getSize(); ++i)
            std::cout << c[i] << " ";
        std::cout << "\n";

        std::cout << "\nString array test\n";
        Array<std::string> s(3);
        s[0] = "one";
        s[1] = "two";
        s[2] = "three";
        for (unsigned int i = 0; i < s.getSize(); ++i)
            std::cout << s[i] << " ";
        std::cout << "\n";

        std::cout << "\nOut-of-range test (should throw)\n";
        try
        {
            std::cout << a[100] << "\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "caught: " << e.what() << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unhandled exception: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
