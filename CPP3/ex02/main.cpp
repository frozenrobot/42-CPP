#include <iostream>
#include "FragTrap.hpp"

int main(void)
{

    FragTrap frag("FR4G");
    FragTrap frag2(frag);
    FragTrap frag3;
    frag3 = frag;
    frag3.attack("target");
    frag.highFivesGuys();
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