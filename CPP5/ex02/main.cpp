#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	// srand(time(NULL));

	Bureaucrat alice("Alice", 1);
	std::cout << alice << std::endl;
	Bureaucrat bob("Bob", 100);
	std::cout << bob << std::endl;
	Form *shrub = new ShrubberyCreationForm("target1");
	std::cout << *shrub << std::endl;
	shrub->beSigned(bob);
	shrub->execute(bob);
	Form *pres = new PresidentialPardonForm("target2");
	std::cout << *pres << std::endl;
	alice.signForm(*pres);
	pres->execute(alice);
	Form *robot = new RobotomyRequestForm("target3");
	std::cout << *robot << std::endl;
	robot->beSigned(alice);
	alice.executeForm(*robot);

	std::cout << "=======" << std::endl;

	try
	{
		bob.executeForm(*pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "=======" << std::endl;

	try
	{
		(*robot).execute(bob);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "=======" << std::endl;

	try
	{
		(*pres).beSigned(bob);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete shrub;
	delete pres;
	delete robot;

	return (0);
}