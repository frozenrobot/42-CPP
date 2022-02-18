#include "WrongAnimal.hpp"

// ANIMAL

WrongAnimal::WrongAnimal(void) : type("none")
{
    std::cout << "Animal constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & toCopy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = toCopy.type;
    return ;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const &toAssign)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &toAssign)
    {
        this->type = toAssign.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "Animal destructor called" << std::endl;
    return ;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void WrongAnimal::setType(std::string newtype)
{
    this->type = newtype;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "< Random animal noises >" << std::endl;
}



// CAT

WrongCat::WrongCat(void)
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    return ;
}

WrongCat::WrongCat(WrongCat const & toCopy) : WrongAnimal(toCopy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    return ;
}

WrongCat & WrongCat::operator=(WrongCat const &toAssign)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    this->type = toAssign.type;
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    return ;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}
