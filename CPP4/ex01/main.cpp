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
    std::cout << " //// PROOF OF DEEP COPY: " << std::endl;
    Cat catto;
    catto.setIdea(0, "Food");
    Cat copycat(catto);
    std::cout << copycat.getIdea(0) << std::endl;
    
    Dog basic;
    Dog tmp = basic;
    basic.setIdea(0, "Shoes");
    tmp.setIdea(0, "Garbage");
    std::cout << basic.getIdea(0) << std::endl;
    std::cout << tmp.getIdea(0) << std::endl;

    //test from subject
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;


}
