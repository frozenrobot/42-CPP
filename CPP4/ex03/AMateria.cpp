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


Cure::Cure(void) : AMateria("cure")
{
    return;
}

Cure::Cure(Cure const & other): AMateria("cure")
{
	return;
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




Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

Character::Character(Character const &toCopy) : _name(toCopy.getName())
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete (this->_materia[i]);
	}
	for (i = 0; i < 4; i++)
	{
		if (toCopy._materia[i])
			this->_materia[i] = toCopy._materia[i]->clone();
	}
		
}

Character & Character::operator=(Character const &toAssign)
{
	this->_name = toAssign.getName();
	for (int i = 0; i < 4; i++)
	{
		if (toAssign._materia[i])
			this->_materia[i] = toAssign._materia[i];
		else
			this->_materia[i] = NULL;
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete (this->_materia[i]);
	}
		
}

std::string const &	Character::getName(void) const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	int i = 0;
	while (i < 4)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = m;
			break;
		}
		i++;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->_materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (this->_materia[idx])
			this->_materia[idx]->use(target);
		else
			std::cout << "Index empty." << std::endl;
	}
	else
		std::cout << "Index out of range." << std::endl;
}



MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		this->_store[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &toCopy)
{
	for (int i = 0; i < 4; i++)
	{
		if (toCopy._store[i])
			this->_store[i] = toCopy._store[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &toAssign)
{
	for (int i = 0; i < 4; i++)
	{
		if (toAssign._store[i])
			this->_store[i] = toAssign._store[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_store[i])
			delete (this->_store[i]);
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;
	while (i < 4)
	{
		if (this->_store[i] == NULL)
		{
			this->_store[i] = m;
			break;
		}
		i++;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_store[i] && this->_store[i]->getType() == type)
			return (this->_store[i]->clone());
	}
	return (0);
}
