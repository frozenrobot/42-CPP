#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): _type(type)
{
    return;
}

AMateria::~AMateria(void)
{
    return;
}

std::string const & AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	return;
}

Ice::Ice(void) : AMateria("ice")
{
    return;
}

Ice::Ice(Ice const & other): AMateria("ice")
{
	
}

Ice::~Ice(void)
{
    return;
}

Ice &Ice::operator=(Ice const &other)
{
	return (*this);
}

AMateria *Ice::clone(void) const
{
	Ice *clone = new Ice(*this);
	return (clone);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "’s wounds *" << std::endl;
}


Cure::Cure(void) : AMateria("ice")
{
    return;
}

Cure::Cure(Cure const & other): AMateria("ice")
{
	
}

Cure::~Cure(void)
{
    return;
}

Cure &Cure::operator=(Cure const &other)
{
	return (*this);
}

AMateria *Cure::clone(void) const
{
	Cure *clone = new Cure(*this);
	return (clone);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << " *" << std::endl;
}