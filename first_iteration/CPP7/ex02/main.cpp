#include "Array.hpp"

template < typename T >
Array<T>::Array(void) : len(0), begin(nullptr)
{
    return ;
}

template < typename T >
Array<T>::Array(size_t length) : len(length), begin(nullptr)
{
    this->begin = new T[length]();
    return ;
}

template < typename T >
Array<T>::Array(Array const &toCopy) : len(0), begin(nullptr)
{
	if (toCopy.len > 0)
	{
		this->len = toCopy.len;
        this->begin = new T[toCopy.len]();
		for (size_t i = 0; i < toCopy.len; i++)
			this->begin[i] = toCopy.begin[i];
	}
}

template < typename T >
Array<T> &Array<T>::operator=(Array<T> const &toAssign)
{
	if (this->len > 0)
		delete[] this->begin;
	this->begin = nullptr;
	if (toAssign.len > 0)
	{
		this->begin = new T[toAssign.len]();
		for (size_t i = 0; i < toAssign.len; i++)
			this->begin[i] = toAssign.begin[i];
	}
	this->len = toAssign.len;
	return (*this);
}

template < typename T >
Array<T>::~Array()
{
	if (this->len > 0)
		delete[] this->begin;
}

template < typename T >
T &Array<T>::operator[](size_t index)
{
	if (index < this->len)
        return (this->begin[index]);
    else
	    throw Array::OutOfLimitsException();
}

template<typename T>
T const &Array<T>::operator[](size_t index) const
{
	return (operator[](index));
}

template < typename T >
size_t Array<T>::size(void) const
{
    return (this->len);
}

int main(void)
{
    Array<char>chararray(5);
    char a = 'a';
    for (int i = 0; i < chararray.size(); i++)
    {
        chararray[i] = a + i;
        std::cout << chararray[i] << " ";
    }
    std::cout << std::endl;

    Array<std::string>strarray(3);
    strarray[0] = "one";
    strarray[1] = "two";
    strarray[2] = "three";
    Array<std::string>newstrarray = strarray;
    for (int i = 0; i < 3; i++)
    {
        std::cout << newstrarray[i] << std::endl;
    }

    try
	{
		chararray[-1] = 'Z';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		chararray[10] = 'Z';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}