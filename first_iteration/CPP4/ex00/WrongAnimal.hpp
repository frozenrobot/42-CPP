#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const & toCopy);
        WrongAnimal &operator=(WrongAnimal const &toAssign);
        ~WrongAnimal();
        std::string getType(void) const;
        void setType(std::string newtype);
        void makeSound(void) const;

    protected:
        std::string type;
};

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const & toCopy);
        WrongCat &operator=(WrongCat const &toAssign);
        ~WrongCat();
        virtual void makeSound(void) const;
};

#endif