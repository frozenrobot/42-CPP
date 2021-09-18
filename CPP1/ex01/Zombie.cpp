#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

Zombie::Zombie(void)
{
    return ;
}

Zombie::~Zombie(void)
{
    return ;
}

void Zombie::announce(void)
{
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName(void)
{
    return (this->_name);
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}