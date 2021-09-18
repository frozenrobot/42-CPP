#include <iostream>

char *capitalize(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 'a' + 'A';
        i++;
    }
    return str;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        std::cout << capitalize(argv[i]);
    }
    std::cout << std::endl;
    return 0;
}
