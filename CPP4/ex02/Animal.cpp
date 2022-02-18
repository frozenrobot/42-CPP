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
    // std::cout << "Animal copy assignment operator called" << std::endl;
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
    Brain *newbrain = new Brain();
    this->brain = newbrain;
    return ;
}

Dog::Dog(Dog const & toCopy) : Animal(toCopy)
{
    Brain *newbrain = new Brain();
    this->brain = newbrain;
    for (int i = 0; i < 100; i++)
    {
        this->brain->ideas[i] = toCopy.brain->ideas[i];
    }
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog & Dog::operator=(Dog const &toAssign)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    this->type = toAssign.type;
    for (int i = 0; i < 100; i++)
    {
        this->brain->ideas[i] = toAssign.brain->ideas[i];
    }
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
    return ;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int n, std::string idea)
{
    if (n >= 0 && n < 100)
    {
        this->brain->ideas[n] = idea;
    }
}

std::string Dog::getIdea(int n)
{
    if (n >= 0 && n < 100)
    {
        return (this->brain->ideas[n]);
    }
    return (NULL);
}



// CAT

Cat::Cat(void)
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    Brain *newbrain = new Brain();
    this->brain = newbrain;
    return ;
}

Cat::Cat(Cat const & toCopy) : Animal(toCopy)
{
    Brain *newbrain = new Brain();
    this->brain = newbrain;
    for (int i = 0; i < 100; i++)
    {
        this->brain->ideas[i] = toCopy.brain->ideas[i];
    }
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat & Cat::operator=(Cat const &toAssign)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    this->type = toAssign.type;
    for (int i = 0; i < 100; i++)
    {
        this->brain->ideas[i] = toAssign.brain->ideas[i];
    }
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
    return ;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int n, std::string idea)
{
    if (n >= 0 && n < 100)
    {
        this->brain->ideas[n] = idea;
    }
}

std::string Cat::getIdea(int n)
{
    if (n >= 0 && n < 100)
    {
        return (this->brain->ideas[n]);
    }
    return (NULL);
}



// BRAIN

Brain::Brain(void)
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const & toCopy)
{
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = toCopy.ideas[i];
    }
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain & Brain::operator=(Brain const &toAssign)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = toAssign.ideas[i];
    }
    return (*this);
}
