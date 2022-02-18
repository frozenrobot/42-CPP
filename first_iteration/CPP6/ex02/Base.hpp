#ifndef BASE_HPP
#define BASE_HPP

// #include <cstdlib>
#include <iostream>

class Base
{
    public:
        virtual ~Base(void) {};
};

class A : public Base
{
    ~A(){};
};

class B : public Base
{
    ~B(){};
};

class C : public Base
{
    ~C(){};
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif