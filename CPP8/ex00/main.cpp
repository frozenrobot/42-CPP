#include  "easyfind.hpp"

template < typename T >
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), value);
    if (it != container.end()) {
        return it;
    }
    throw std::exception();
}

int main(void)
{
		std::list<int> lst;
		for (int i = 0; i < 50; i++)
			lst.push_back(i);
        try
        {
            std::list<int>::iterator it = easyfind(lst, 42);
            std::cout << *it << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        try
        {
            std::list<int>::iterator it = easyfind(lst, 100);
            std::cout << *it << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
}