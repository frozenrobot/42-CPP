#include "Zombie.hpp"

int main(void)
{
    Zombie *horde = zombieHorde(42, "NaMe");
    for (int i = 0; i < 42; i++)
    {
        std::cout << i + 1 << ": ";
        horde[i].announce();
    }
    delete [] horde;
}