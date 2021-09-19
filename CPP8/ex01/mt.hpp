
#ifndef MT_HPP
# define MT_HPP

# include <stack>
# include <deque>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack<T> const &other);
	virtual ~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack<T> &operator=(MutantStack<T> const &other);

	iterator begin(void);
	iterator end(void);
};

# include "mt.ipp"

#endif
