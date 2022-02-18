#include "span.hpp"

Span::Span(size_t n) : len(n)
{
    return;
}

Span::~Span()
{
	this->span.clear();
}

Span::Span(Span const &toCopy): len(toCopy.len)
{
	this->span.clear();
	this->span = toCopy.span;
}

Span &Span::operator=(Span const &toAssign)
{
	this->len = toAssign.len;
	this->span.clear();
	this->span = toAssign.span;
	return (*this);
}

void Span::addNumber(int num)
{
	if (this->span.size() < this->len)
		this->span.insert(num);
    else
        throw Span::FullSpanException();
}

size_t Span::longestSpan(void) const
{
	if (this->span.size() <= 1)
		throw Span::EmptySpanException();
    else
    {
        int max = *std::max_element(this->span.begin(), this->span.end());
        int min = *std::min_element(this->span.begin(), this->span.end());
        return (std::abs(max - min));
    }
}

size_t Span::shortestSpan(void) const
{
	if (this->span.size() <= 1)
		throw Span::EmptySpanException();
    else
    {
        std::multiset<int>::iterator begin = this->span.begin();
        std::multiset<int>::iterator next;
        size_t mindist = *std::max_element(this->span.begin(), this->span.end());
        size_t dist;
        while (begin != this->span.end())
        {
            next = begin;
            while (next != this->span.end())
            {
                if (begin != next)
                {
                    dist = std::abs(*next - *begin);
                    if (dist < mindist)
                        mindist = dist;
                }
                next++;
            }
            begin++;
        }
        return (mindist);
    }
}