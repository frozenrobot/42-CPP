#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed const & toCopy);
        Fixed(const int intparam);
        Fixed(const float floatparam);
        Fixed &operator=(Fixed const &toAssign);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        Fixed operator+(const Fixed & num) const;
        Fixed operator-(const Fixed & num) const;
        Fixed operator*(const Fixed & num) const;
        Fixed operator/(const Fixed & num) const;

        Fixed & operator++(void);            //pre increment
        Fixed operator++(int);              //post increment
        Fixed & operator--(void);            //pre decrement
        Fixed operator--(int);              //post decrement

        bool operator>(Fixed const & num) const;
        bool operator<(Fixed const & num) const;
        bool operator>=(Fixed const & num) const;
        bool operator<=(Fixed const & num) const;
        bool operator==(Fixed const & num) const;
        bool operator!=(Fixed const & num) const;
    
        static Fixed & min(Fixed &u, Fixed &v);
        const static Fixed & min(const Fixed &u, const Fixed &v);
        static Fixed & max(Fixed &u, Fixed &v);
        const static Fixed & max(const Fixed &u, const Fixed &v);

    private:
        int _n;
        static const int fracBit = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
