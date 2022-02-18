#include "HumanB.hpp"

void HumanB::attack(void) const
{
    std::string weapon = _weapon ? _weapon->getType() : "...oops, nothing";
    std::cout << this->_name << " attacks with his " << weapon << std::endl;
}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
    this->_name = name;
    return;
}

HumanB::~HumanB(void)
{
    return;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}