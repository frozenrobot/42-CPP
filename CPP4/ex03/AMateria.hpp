#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria;
class Ice;
class Cure;
class ICharacter;
class Character;
class IMateriaSource;
class MateriaSource;

class AMateria
{
    protected:
        std::string const _type;
    public:
        AMateria(std::string const & type);
        virtual ~AMateria(void);
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

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_materia[4];
    public:
        Character(std::string name);
        Character (Character const &toCopy);
        virtual ~Character();
        Character &operator=(Character const &toAssign);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_store[4];
    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const &toCopy);
        MateriaSource &operator=(MateriaSource const &toAssign);
        virtual ~MateriaSource();

        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const & type);
};

#endif