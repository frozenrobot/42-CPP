#include "iter.hpp"

template < typename T >
void iter(T *array, size_t length, void (*func)(T &elem))
{
    for (size_t i = 0; i < length; i++)
    {
        (*func)(array[i]);
    }
}

template < typename T >
void output(T &elem)
{
    std::cout << elem << std::endl;
}

int main(void)
{
    float floatarray[3] = {1.5, 2.7, 3.1};
    iter<float>(floatarray, 3, &output);
    std::string strarray[3] = {"one", "two", "three"};
    iter<std::string>(strarray, 3, &output);
    bool boolarray[2] = {true, false};
    iter<bool>(boolarray, 2, &output);
}