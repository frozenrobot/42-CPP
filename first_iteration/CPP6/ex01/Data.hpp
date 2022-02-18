#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

struct Data
{
    Data(){}
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif