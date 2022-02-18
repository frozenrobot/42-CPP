#include <iostream>
#include "DiamondTrap.hpp"

int main(void)
{

    DiamondTrap diam("DI4M");
    DiamondTrap diam2(diam);
    DiamondTrap diam3("D3");
    diam3.attack("target");
    diam3 = diam;
    diam3.highFivesGuys();
    diam.whoAmI();
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