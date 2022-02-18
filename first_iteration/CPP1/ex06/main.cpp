#include "Karen.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 0;
    }
    Karen karen;
    karen.complain(argv[1]);
}