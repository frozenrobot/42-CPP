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
        throw std::exception();
}

size_t Span::longestSpan(void) const
{
	if (this->span.size() <= 1)
		throw std::exception();
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
		throw std::exception();
    else
    {
        std::multiset<int>::iterator begin = this->span.begin();
        std::multiset<int>::iterator prev;
        size_t mindist = *std::max_element(this->span.begin(), this->span.end());
        size_t dist;
        prev = begin;
        begin++;
        while (begin != this->span.end())
        {
            dist = std::abs(*prev - *begin);
            if (dist < mindist)
                mindist = dist;
            begin++;
            prev++;
        }
        return (mindist);
    }
}