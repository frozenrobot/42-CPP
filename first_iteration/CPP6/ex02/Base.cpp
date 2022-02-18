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
    identify(&p);
}