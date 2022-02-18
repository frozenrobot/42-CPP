#include "Zombie.hpp"

int main(void)
{
    Zombie zombie1;
    // Zombie zombie2;
    Zombie *zombie2p;

    zombie1.setName("Mud");
    // zombie2p = &zombie2;
    zombie2p = newZombie("Boot");
    randomChump("Chump");
    zombie1.announce();
    zombie2p->announce();
    delete zombie2p;
}