#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("unknown"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap constructor called for name " << name << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const & toCopy)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    this->_name = toCopy._name;
    this->_hit_points = toCopy._hit_points;
    this->_energy_points = toCopy._energy_points;
    this->_attack_damage = toCopy._attack_damage;
    return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &toAssign)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &toAssign)
    {
        this->_name = toAssign._name;
        this->_hit_points = toAssign._hit_points;
        this->_energy_points = toAssign._energy_points;
        this->_attack_damage = toAssign._attack_damage;
    }
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called" << std::endl;
    return ;
}

void ClapTrap::attack(std::string const & target)
{
    std::cout << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hit_points = (this->_hit_points > amount ? this->_hit_points - amount : 0);
    std::cout << this->_name << " loses " << amount << " hit points by taking damage. " << this->_hit_points << " hit points left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->_hit_points += amount;
    std::cout << this->_name << " gains " << amount << " hit points by repair. " << this->_hit_points << " hit points left." << std::endl;
}