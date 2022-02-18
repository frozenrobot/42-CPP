#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat alice("Alice", 75);
	std::cout << alice << std::endl;
	alice.increaseGrade();
	std::cout << alice.getGrade() << std::endl;
	alice.decreaseGrade();
	std::cout << alice.getGrade() << std::endl;

	try
	{
		Bureaucrat bob("Bob", 0);
		std::cout << bob << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

    try
	{
		Bureaucrat bob("Bob", 150);
		std::cout << bob << std::endl;
        bob.decreaseGrade();
        std::cout << bob.getGrade() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << alice << std::endl;

	return (0);
}
