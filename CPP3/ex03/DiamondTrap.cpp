#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap constructor called for name " << name << std::endl;
    this->_claptrap_name = name.append("_clap_name");
    this->_hit_points = this->FragTrap::_hit_points;
    this->_energy_points = this->ScavTrap::_energy_points;
    this->_attack_damage = this->FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(DiamondTrap const & toCopy) : ClapTrap(toCopy)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &toAssign)
{
    DiamondTrap::copy(toAssign);
    return(*this);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "Name: " << this->_name << std::endl;
    std::cout << "ClapTrap::Name: " << this->_claptrap_name << std::endl;
}