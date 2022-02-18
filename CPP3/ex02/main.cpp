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
	return (0);
}