#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(Animal const & toCopy);
        Animal &operator=(Animal const &toAssign);
        virtual ~Animal();
        std::string getType(void) const;
        void setType(std::string newtype);
        virtual void makeSound(void) const = 0;

    protected:
        std::string type;
};

class Brain
{
    public:
        Brain();
        Brain(Brain const & toCopy);
        Brain &operator=(Brain const &toAssign);
        virtual ~Brain();
        std::string ideas[100];
};

class Dog : public Animal
{
    public:
        Dog();
        Dog(Dog const & toCopy);
        Dog &operator=(Dog const &toAssign);
        ~Dog();
        virtual void makeSound(void) const;
        void setIdea(int n, std::string idea);
        std::string getIdea(int n);

    private:
        Brain *brain;
};

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat const & toCopy);
        Cat &operator=(Cat const &toAssign);
        ~Cat();
        virtual void makeSound(void) const;
        void setIdea(int n, std::string idea);
        std::string getIdea(int n);
    
    private:
        Brain *brain;
};

#endif