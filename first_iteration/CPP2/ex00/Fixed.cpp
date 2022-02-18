#include "Fixed.hpp"

Fixed::Fixed(void): _n(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(Fixed const &toCopy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_n = toCopy.getRawBits();
    return ;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed & Fixed::operator=(Fixed const &toAssign)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &toAssign)
        this->_n = toAssign.getRawBits();
    return (*this);
}

int Fixed::getRawBits (void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_n);
}

void Fixed::setRawBits ( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    return ;
}