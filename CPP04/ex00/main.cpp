#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;

    std::cout << "\n\033[1;37m--- WrongAnimal demo (no virtual) ---\033[0m\n";
    const WrongAnimal *wrong = new WrongAnimal();
    const WrongAnimal *wrongCatAsWrongAnimal = new WrongCat();
    std::cout << wrong->getType() << std::endl;
    std::cout << wrongCatAsWrongAnimal->getType() << std::endl;
    wrong->makeSound();                  // WrongAnimal sound
    wrongCatAsWrongAnimal->makeSound();  // Still WrongAnimal sound (no virtual)
    delete wrong;
    delete wrongCatAsWrongAnimal;
    return 0;
}