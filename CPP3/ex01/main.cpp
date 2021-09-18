#include <iostream>
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap scav("SC4V");
    ScavTrap scav2(scav);
    ScavTrap scav3;
    scav3 = scav;
    scav3.attack("target");
    scav.guardGate();
	// ClapTrap clap("CL4P");
    // ClapTrap palc("P4LC");
    // ClapTrap clap2;

    // clap.attack("P4LC");
    // palc.takeDamage(0);
    // palc.beRepaired(5);
    // clap2 = clap;
    // clap2.attack("PL4C");
	return (0);
}