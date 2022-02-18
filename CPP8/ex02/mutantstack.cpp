template < typename T >
MutantStack<T>::MutantStack(void) : std::stack<T>()
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
