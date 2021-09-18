#include "Animal.hpp"

// ANIMAL

Animal::Animal(void) : type("none")
{
    std::cout << "Animal constructor called" << std::endl;
    return ;
}

Animal::Animal(Animal const & toCopy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = toCopy.type;
    return ;
}

Animal & Animal::operator=(Animal const &toAssign)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &toAssign)
    {
        this->type = toAssign.type;
    }
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
    return ;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void Animal::setType(std::string newtype)
{
    this->type = newtype;
}

void Animal::makeSound(void) const
{
    std::cout << "< Random animal noises >" << std::endl;
}


// DOG

Dog::Dog(void)
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    return ;
}

Dog::Dog(Dog const & toCopy) : Animal(toCopy)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog & Dog::operator=(Dog const &toAssign)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    this->type = toAssign.type;
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
    return ;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof!" << std::endl;
}



// CAT

Cat::Cat(void)
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    return ;
}

Cat::Cat(Cat const & toCopy) : Animal(toCopy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    return ;
}

Cat & Cat::operator=(Cat const &toAssign)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    this->type = toAssign.type;
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    return ;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}
