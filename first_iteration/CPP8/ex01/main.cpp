#include "span.hpp"

#include <vector>

int main()
{
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span span(1000);
    for (int i = 0; i < 5; i++)
	{
		span = Span(1000);
		for (int i = 0; i < 1000; i++)
			span.addNumber(rand() % 100000);
        std::cout << span.shortestSpan() << std::endl;
        std::cout << span.longestSpan() << std::endl;
    }

    for (int i = 0; i < 5; i++)
	{
		span = Span(5);
		for (int i = 0; i < 5; i++)
			span.addNumber(rand() % 100000);
        std::cout << span.shortestSpan() << std::endl;
        std::cout << span.longestSpan() << std::endl;
    }

    try
    {
        span.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Span span2(5);
        span2.addNumber(42);
        std::cout << span2.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}