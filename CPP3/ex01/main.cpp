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
	return (0);
}