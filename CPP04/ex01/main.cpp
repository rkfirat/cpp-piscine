#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal* animal[100];
    for (size_t i = 0; i < 50; i++)
    {
        animal[i] = new Cat();
    }
    for (size_t i = 50; i < 100; i++)
    {
        animal[i] = new Dog();
    }
    for (size_t i = 0; i < 100 ; i++)
    {
        delete animal[i];
    }
    
    return 0;
}