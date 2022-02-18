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

    private:
        int _n;
        static const int fracBit = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
