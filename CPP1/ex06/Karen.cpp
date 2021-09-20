#include "Karen.hpp"

Karen::Karen(void)
{
    this->identity[0] = "DEBUG";
    this->identity[1] = "INFO";
    this->identity[2] = "WARNING";
    this->identity[3] = "ERROR";
}

void Karen::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n" << std::endl;
}

void Karen::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n" << std::endl;
}

void Karen::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n" << std::endl;
}

void Karen::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void Karen::complain( std::string level )
{
    int i = 0;
    while (i < 4)
    {
        if (this->identity[i] == level)
            break;
        i++;
    }
    switch (i)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        case 4:
            std::cout << " [ Probably complaining about insignificant problems ]" << std::endl;
    }
}