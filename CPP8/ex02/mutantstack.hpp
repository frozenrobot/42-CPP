#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template < typename T >
class MutantStack: public std::stack<T>
{
    public:
        MutantStack(void);
        MutantStack(MutantStack<T> const &toCopy);
        MutantStack<T> &operator=(MutantStack<T> const &toAssign);
        virtual ~MutantStack(void);
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin(void);
        iterator end(void);
};

#include "mutantstack.cpp"

#endif