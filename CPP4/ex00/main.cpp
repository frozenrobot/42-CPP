#include <iostream>
#include "Animal.hpp"
// #include "WrongAnimal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    //wrong version
//     const WrongAnimal* meta = new WrongAnimal();
//     const WrongAnimal* i = new WrongCat();
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound();
//     meta->makeSound();
}