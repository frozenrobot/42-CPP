#include "Fixed.hpp"

Fixed::Fixed(void): _n(0)
{
    // std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const int intparam)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_n = intparam << this->fracBit;
}

Fixed::Fixed(const float floatparam)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_n = (int)(roundf(floatparam * (1 << this->fracBit)));
}

Fixed::Fixed(Fixed const &toCopy)
{
    // std::cout << "Copy constructor called" << std::endl;
    this->_n = toCopy.getRawBits();
    return ;
}

Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed & Fixed::operator=(Fixed const &toAssign)
{
    // std::cout << "Assignation operator called" << std::endl;
    if (this != &toAssign)
        this->_n = toAssign.getRawBits();
    return (*this);
}



Fixed Fixed::operator+(const Fixed & num) const
{
    Fixed instance;
    instance.setRawBits(this->_n + num.getRawBits());
    return (instance);
}

Fixed Fixed::operator-(const Fixed & num) const
{
    Fixed instance;
    instance.setRawBits(this->_n - num.getRawBits());
    return (instance);
}

Fixed Fixed::operator*(const Fixed & num) const
{
    Fixed instance;
    instance.setRawBits(this->_n * num.getRawBits());
    return (instance);
}

Fixed Fixed::operator/(const Fixed & num) const
{
    Fixed instance;
    instance.setRawBits(this->_n / num.getRawBits());
    return (instance);
}




bool Fixed::operator>(Fixed const & num) const
{
    return (this->_n > num.getRawBits());
}

bool Fixed::operator<(Fixed const & num) const
{
    return (this->_n < num.getRawBits());
}

bool Fixed::operator>=(Fixed const & num) const
{
    return (this->_n >= num.getRawBits());
}

bool Fixed::operator<=(Fixed const & num) const
{
    return (this->_n <= num.getRawBits());
}

bool Fixed::operator==(Fixed const & num) const
{
    return (this->_n == num.getRawBits());
}

bool Fixed::operator!=(Fixed const & num) const
{
    return (this->_n != num.getRawBits());
}



Fixed & Fixed::operator++(void) //pre increment
{
    (this->_n)++;
    return (*this);
}

Fixed Fixed::operator++(int) //post increment
{
    Fixed instance(*this); //declares new instance
    operator++(); //increment in original instance
    return (instance); //returns new instance before increment
}

Fixed & Fixed::operator--(void)
{
    (this->_n)--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed instance(*this);
    operator--();
    return (instance);
}



Fixed & Fixed::min(Fixed &u, Fixed &v)
{
    return (u < v ? u : v);
}

const Fixed & Fixed::min(const Fixed &u, const Fixed &v)
{
    return (u < v ? u : v);
}

Fixed & Fixed::max(Fixed &u, Fixed &v)
{
    return (u > v ? u : v);
}

const Fixed & Fixed::max(const Fixed &u, const Fixed &v)
{
    return (u > v ? u : v);
}



int Fixed::getRawBits (void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->_n);
}

void Fixed::setRawBits ( int const raw )
{
    // std::cout << "setRawBits member function called" << std::endl;
    return ;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_n / (float)(1 << this->fracBit));
}

int Fixed::toInt(void) const
{
    return ((int)(this->_n >> this->fracBit));
}

std::ostream &operator<<(std::ostream & o, const Fixed &instance)
{
    o << instance.toFloat();
    return (o);
}