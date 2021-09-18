#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const & toCopy);
        ScavTrap &operator=(ScavTrap const &toAssign);
        ~ScavTrap();
        void attack(std::string const & target);
        void guardGate(void);
};

#endif