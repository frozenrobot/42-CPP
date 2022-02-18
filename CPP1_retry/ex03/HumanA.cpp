#include "HumanA.hpp"

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
    return ;
}

void HumanA::setWeapon(Weapon& weapon)
{
    this->_weapon = weapon;
}

// HumanA::HumanA(void)
// {
//     Weapon words = Weapon("words");
//     Weapon& wordsREF = words;
//     this->_weapon = words;
//     return;
// }

HumanA::~HumanA(void)
{
    return;
}

