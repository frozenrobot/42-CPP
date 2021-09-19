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

template < typename T >
MutantStack<T>::MutantStack() : std::stack<T>()
{
    return;
}

template < typename T >
MutantStack<T>::MutantStack(MutantStack<T> const &toCopy) :	std::stack<T>(toCopy)
{
    return ;
}

template < typename T >
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &toAssign)
{
	this->c = toAssign.c;
	return (*this);
}

template < typename T >
MutantStack<T>::~MutantStack(void)
{
    return ;
}

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

#endif