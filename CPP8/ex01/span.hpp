#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>

class Span
{
    private:
        size_t len;
        std::multiset<int> span;
    public:
        Span(size_t n);
        ~Span(void);
        Span(Span const &toCopy);
        Span &operator=(Span const &toAssign);
        void addNumber(int num);
        size_t shortestSpan(void) const;
        size_t longestSpan(void) const;
};

#include "span.cpp"

#endif