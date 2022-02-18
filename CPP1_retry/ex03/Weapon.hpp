#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    public:
        void setType(std::string type);
        std::string const& getType(void);
        Weapon(std::string weapon);
        Weapon(void);
        ~Weapon(void);

    private:
        std::string _type;
};

#endif