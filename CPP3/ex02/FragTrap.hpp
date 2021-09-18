#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const & toCopy);
        FragTrap &operator=(FragTrap const &toAssign);
        ~FragTrap();
        void highFivesGuys(void);
};

#endif