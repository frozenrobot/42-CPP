#include "whatever.hpp"

template < typename T >
void swap(T & x, T & y)
{
    T temp = x;
    x = y;
    y = temp;
}

template < typename T >
T & min(T & x, T & y)
{
	if (y > x)
		return (x);
	return (y);
}

template < typename T >
T & max(T & x, T & y)
{
	if (x > y)
		return (x);
	return (y);
}


int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}


// int main(void)
// {
// 	int a = 21;
// 	int b = 42;

// 	std::cout << "a: " << a << ", b: " << b << std::endl;
// 	swap(a, b);
//     std::cout << "SWAPPED: \n";
// 	std::cout << "a: " << a << ", b: " << b << std::endl;
//     std::cout << "=========\n";
// 	std::cout << "min(a, b) = " << min(a, b) << std::endl;
// 	std::cout << "max(a, b) = " << max(a, b) << std::endl;
//     std::cout << "=========\n";

// 	std::string c = "str1";
// 	std::string d = "str2";

// 	std::cout << "c: " << c << ", d: " << d << std::endl;
// 	swap(c, d);
//     std::cout << "SWAPPED: \n";
// 	std::cout << "c: " << c << ", d: " << d << std::endl;
//     std::cout << "=========\n";
// 	std::cout << "min(c, d) = " << min(c, d) << std::endl;
// 	std::cout << "max(c, d) = " << max(c, d) << std::endl;
//     std::cout << "=========\n";

// 	d = "str1";
//     std::cout << "&c: " << &c << std::endl;
//     std::cout << "&d: " << &d << std::endl;
//     std::cout << "min(c, d) = " << min(c, d) << std::endl;
//     std::cout << "Address: " << &(min(c, d)) << std::endl;
// 	return (0);
// }