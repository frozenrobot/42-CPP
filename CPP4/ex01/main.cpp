#include <iostream>
#include "Animal.hpp"

int main()
{
    Animal *animals[10];
    for (int i = 0; i < 5; i++)
    {
        animals[i] = new Dog();
    }
    for (int i = 5; i < 10; i++)
    {
        animals[i] = new Cat();
    }

    for (int i = 0; i < 10; i++)
    {
        delete animals[i];
    }

    //to demonstrate deep copy
    Cat catto;
    catto.setIdea(0, "Food");
    Cat copycat(catto);
    std::cout << " //// PROOF OF DEEP COPY: " << copycat.getIdea(0) << std::endl;

}

// int main()
// {
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// delete j;//should not create a leak
// delete i;
// }