#include "Fixed.hpp"

Fixed::Fixed() : _n(0)
{
    return;
}

Fixed::Fixed(const int intparam)
{
    this->_n = intparam << this->fracBit;
}

Fixed::Fixed(const float floatparam)
{
    this->_n = (int)(roundf(floatparam * (1 << this->fracBit)));
}

Fixed::Fixed(Fixed const & toCopy)
{
    *this = toCopy;
}

Fixed::~Fixed()
{
    return;
}

Fixed & Fixed::operator=(Fixed const & instance)
{
    if (this != &instance)
        this->_n = instance.getRawBits();
    return (*this);
}




int Fixed::getRawBits(void) const
{
    return (this->_n);
}

void Fixed::setRawBits(int const raw)
{
    this->_n = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_n / (float)(1 << this->fracBit));
}

int Fixed::toInt(void) const
{
    return ((int)(this->_n >> this->fracBit));
}




bool Fixed::operator>(Fixed const & instance) const
{
    return (this->_n > instance.getRawBits());
}

bool Fixed::operator<(Fixed const & instance) const
{
    return (this->_n < instance.getRawBits()); 
}

bool Fixed::operator>=(Fixed const & instance) const
{
    return (this->_n >= instance.getRawBits()); 
}

bool Fixed::operator<=(Fixed const & instance) const
{
    return (this->_n <= instance.getRawBits());
}

bool Fixed::operator==(Fixed const & instance) const
{
    return (this->_n == instance.getRawBits());
}
bool Fixed::operator!=(Fixed const & instance) const
{
    return !(this->_n == instance.getRawBits());
}




Fixed Fixed::operator+(Fixed const & instance) const
{
    Fixed newFixed;
    newFixed.setRawBits(this->_n + instance.getRawBits());
    return (newFixed);
}

Fixed Fixed::operator-(Fixed const & instance) const
{
    Fixed newFixed;
    newFixed.setRawBits(this->_n - instance.getRawBits());
    return (newFixed);
}

Fixed Fixed::operator*(Fixed const & instance) const
{
    Fixed newFixed;
    newFixed.setRawBits((this->_n * instance.getRawBits()) >> this->fracBit);
    return (newFixed);
}

Fixed Fixed::operator/(Fixed const & instance) const
{
    Fixed newFixed;
    newFixed.setRawBits((this->_n << this->fracBit) / instance.getRawBits());
    return (newFixed);
}

Fixed & Fixed::operator++(void)
{
    (this->_n)++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed newFixed(*this);
    (this->_n)++;
    return (newFixed);
}

Fixed & Fixed::operator--(void)
{
    (this->_n)--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed newFixed(*this);
    (this->_n)--;
    return (newFixed);
}



Fixed & Fixed::min(Fixed &u, Fixed &v)
{
    if (u < v)
        return u;
    return v;
}

const Fixed & Fixed::min(const Fixed &u, const Fixed &v)
{
    if (u < v)
        return u;
    return v;
}

Fixed & Fixed::max(Fixed &u, Fixed &v)
{
    if (u > v)
        return u;
    return v;
}

const Fixed & Fixed::max(const Fixed &u, const Fixed &v)
{
    if (u > v)
        return u;
    return v;
}



std::ostream &operator<<(std::ostream & o, const Fixed &instance)
{
    o << instance.toFloat();
    return (o);
}
