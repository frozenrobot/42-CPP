#include "Number.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }
    Number num(argv[1]);
    num.outputInfo();
}