#include <iostream>
#include "Animal.hpp"

int main()
{
    // const Animal* j = new Animal();
    const Animal* i = new Cat();
    Cat k;
    i->makeSound();
    k.setIdea(0, "Food");
    // delete j;//should not create a leak
    delete i;
}