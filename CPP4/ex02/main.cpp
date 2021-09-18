#include <iostream>
#include "Animal.hpp"

int main()
{
    const Animal* j = new Animal();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
}