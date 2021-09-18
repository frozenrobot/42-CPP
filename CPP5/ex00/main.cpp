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

	return (0);
}



// #include <iostream>
// #include <exception>
// using namespace std;

// struct MyException : public exception {
//    const char * what () const throw () {
//       return "C++ Exception";
//    }
// };
 
// int main() {
//    try {
//       throw MyException();
//    } catch(MyException& e) {
//       std::cout << "MyException caught" << std::endl;
//       std::cout << e.what() << std::endl;
//    } catch(std::exception& e) {
//       //Other errors
//    }
// }