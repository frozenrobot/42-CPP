#include "mutantstack.hpp"

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n\n";
	
	std::stack<int> stack;
	stack.push(5);
	stack.push(17);
	std::cout << stack.top() << std::endl;
	stack.pop();
	std::cout << stack.size() << std::endl;
	stack.push(3);
	stack.push(5);
	stack.push(737);
	stack.push(0);
	for (int i = 0; i < 5; i++) {
		std::cout << stack.top() << std::endl;
		stack.pop();
	}

	std::cout << "\n\n";

	std::cout << mstack.empty() << std::endl;
	std::cout << mstack.size() << std::endl;

	MutantStack<int> mstack2;
	MutantStack<int> mstack3;
	mstack2.push(2);
	mstack3.push(3);
	std::cout << mstack2.top() << std::endl;
	std::cout << mstack3.top() << std::endl;
	mstack2.swap(mstack3);
	std::cout << mstack2.top() << std::endl;
	std::cout << mstack3.top() << std::endl;
}