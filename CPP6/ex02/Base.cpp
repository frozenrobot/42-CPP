#include "Base.hpp"

Base *generate(void)
{
    int choice = rand() % 3;
    Base *instance;
    switch (choice)
    {
    case 0:
        instance = new A;
        break;
    case 1:
        instance = new B;
        break;
    case 2:
        instance = new C;
        break;
    }
    return (instance);
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p) != nullptr)
		std::cout << "A";
	else if (dynamic_cast<B *>(p) != nullptr)
		std::cout << "B";
	else if (dynamic_cast<C *>(p) != nullptr)
		std::cout << "C";
}

void identify(Base& p)
{
    char type = 0;
    Base identity;
    try
    {
        identity = dynamic_cast<A &>(p);
        type = 'A';
    }
    catch(const std::exception& e)
    {}

    try
    {
        identity = dynamic_cast<B &>(p);
        type = 'B';
    }
    catch(const std::exception& e)
    {}

    try
    {
        identity = dynamic_cast<C &>(p);
        type = 'C';
    }
    catch(const std::exception& e)
    {}

    std::cout << type;

}
