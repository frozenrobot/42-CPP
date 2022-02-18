#include "Data.hpp"

int main(void)
{
    Data data;
    Data *ptr = &data;
    std::cout << ptr << std::endl;
    uintptr_t temp = serialize(ptr);
    Data *ptr2 = deserialize(temp);
    std::cout << ptr2 << std::endl;
}