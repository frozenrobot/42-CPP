#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(Animal const & toCopy);
        Animal &operator=(Animal const &toAssign);
        ~Animal();
        std::string getType(void) const;
        void setType(std::string newtype);
        virtual void makeSound(void) const;

    protected:
        std::string type;
};

class Dog : public Animal
{
    public:
        Dog();
        Dog(Dog const & toCopy);
        Dog &operator=(Dog const &toAssign);
        ~Dog();
        virtual void makeSound(void) const;
};

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat const & toCopy);
        Cat &operator=(Cat const &toAssign);
        ~Cat();
        virtual void makeSound(void) const;
};

#endif