#include <iostream>
#include "DiamondTrap.hpp"

int main(void)
{

    DiamondTrap diam("DI4M");
    DiamondTrap diam2(diam);
    DiamondTrap diam3("D3");
    diam3.attack("target");
    diam3 = diam;
    diam3.guardGate();
    diam3.highFivesGuys();
    diam.whoAmI();
	return (0);
}