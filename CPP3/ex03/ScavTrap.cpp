#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called for name " << name << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & toCopy) : ClapTrap(toCopy)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &toAssign)
{
    ClapTrap::copy(toAssign);
    return(*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
    std::cout << "ScavTrap" << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << this->_name << " has entered Gate Keeper mode." << std::endl;
}





// ScavTrap::ScavTrap(void) : _name("unknown"), _hit_points(10), _energy_points(10), _attack_damage(0)
// {
    // std::cout << "ScavTrap constructor called" << std::endl;
//     return ;
// }

// ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
// {
//     std::cout << "ScavTrap constructor called for name " << name << std::endl;
//     return ;
// }

// ScavTrap::ScavTrap(ScavTrap const & toCopy) : ClapTrap(toCopy._name)
// {
//     std::cout << "ScavTrap copy constructor called" << std::endl;
//     return ;
// }

// ScavTrap & ScavTrap::operator=(ScavTrap const &toAssign)
// {
//     std::cout << "ScavTrap copy assignment operator called" << std::endl;
//     if (this != &toAssign)
//     {
//         this->_name = toAssign._name;
//         this->_hit_points = toAssign._hit_points;
//         this->_energy_points = toAssign._energy_points;
//         this->_attack_damage = toAssign._attack_damage;
//     }
//     return (*this);
// }

// ScavTrap::~ScavTrap(void)
// {
//     std::cout << "ScavTrap destructor called" << std::endl;
//     return ;
// }