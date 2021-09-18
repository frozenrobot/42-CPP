#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("CL4P");
    ClapTrap palc("P4LC");
    ClapTrap clap2;

    clap.attack("P4LC");
    palc.takeDamage(0);
    palc.beRepaired(5);
    clap2 = clap;
    clap2.attack("PL4C");
	return (0);
}