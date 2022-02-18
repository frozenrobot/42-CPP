#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template < typename T >
class Array
{
    private:
        T *begin;
        size_t len;
    public:
        Array(void);
        Array(size_t length);
        Array(Array<T> const &other);
	    virtual ~Array();
        Array &operator=(Array const &other);
        T const &operator[](size_t index) const;
        T &operator[](size_t index);
        size_t size(void) const;
        
        class OutOfLimitsException: public std::exception {
            virtual const char* what() const throw()
            {
                return "EXCEPTION: Index value outside limits.";
            }
	    };
};

#endif