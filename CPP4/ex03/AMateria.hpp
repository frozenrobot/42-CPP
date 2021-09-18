#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria
{
    protected:
        std::string const _type;
    public:
        AMateria(std::string const & type);
        ~AMateria(void);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

class Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice const &other);
        ~Ice(void);
        Ice &operator=(Ice const &other);
        
        AMateria* clone() const;
        void use(ICharacter& target);
};

class Cure : public AMateria
{
    public:
        Cure();
        Cure(Cure const &other);
        ~Cure(void);
        Cure &operator=(Cure const &other);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif