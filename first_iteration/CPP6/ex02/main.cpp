#include "Base.hpp"

int main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		Base *abc = generate();
		std::cout << "Test " << i << ": ";
		identify(abc);
		std::cout << ", ";
		Base &ref = *abc;
		identify(ref);
		std::cout << std::endl;
		delete abc;
	}

	return (0);
}