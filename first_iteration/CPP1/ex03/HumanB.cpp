#include "HumanB.hpp"
// #include "Weapon.hpp"

void HumanB::attack(void)
{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}

HumanB::HumanB(std::string name) : _name(name)
{
    Weapon& weapon;
    this->_weapon = weapon;
    return;
}

// HumanB::HumanB(void) : _name("random person")
// {
//     return;
// }

HumanB::~HumanB(void)
{
    return;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = weapon;
}