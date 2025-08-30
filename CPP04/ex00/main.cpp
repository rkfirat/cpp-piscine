#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\033[1;32m=== CORRECT ANIMALS (with virtual functions) ===\033[0m" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();  // Will call Cat::makeSound
    j->makeSound();  // Will call Dog::makeSound
    meta->makeSound(); // Will call Animal::makeSound
    delete meta;
    delete i;
    delete j;

    std::cout << "\n\033[1;31m=== WRONG ANIMALS (without virtual functions) ===\033[0m" << std::endl;
    const WrongAnimal *wrong_meta = new WrongAnimal();
    const WrongAnimal *wrong_cat = new WrongCat();
    std::cout << wrong_cat->getType() << " " << std::endl;
    wrong_cat->makeSound();  // Will call WrongAnimal::makeSound (NOT WrongCat::makeSound)
    wrong_meta->makeSound(); // Will call WrongAnimal::makeSound
    delete wrong_meta;
    delete wrong_cat;  // ⚠️ DANGEROUS: WrongCat destructor might not be called properly
    
    return 0;
}