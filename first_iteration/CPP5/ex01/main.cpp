#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat alice("Alice", 125);
	std::cout << alice << std::endl;
	Form form1("Form1", 100, 50);
	std::cout << form1 << std::endl;

	std::cout << "============" << std::endl;

	try
	{
		alice.signForm(form1);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "============" << std::endl;

	try
	{
		for (int i = 0; i < 30; i++)
			alice.increaseGrade();
		std::cout << alice << std::endl;
		form1.beSigned(alice);
		std::cout << form1 << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
