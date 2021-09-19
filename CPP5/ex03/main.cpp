#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat alice("Alice", 1);
	std::cout << alice << std::endl;
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	try
	{
		rrf->execute(alice);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	alice.signForm(*rrf);
	rrf->execute(alice);
}