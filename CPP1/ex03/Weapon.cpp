#include "Weapon.hpp"

void Weapon::setType(std::string type)
{
    this->_type = type;
    return;
}

std::string Weapon::getType(void)
{
    return (this->_type);
}

Weapon::Weapon(std::string weapon) : _type(weapon)
{
    return;
}

Weapon::Weapon(void) : _type("... oops, nothing")
{
    return;
}

Weapon::~Weapon(void)
{
    return;
}