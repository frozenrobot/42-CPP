#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const & toCopy);
        DiamondTrap &operator=(DiamondTrap const &toAssign);
        ~DiamondTrap();
        void attack(std::string const & target);
        void whoAmI(void);

    private:
        std::string _claptrap_name;
};

#endif