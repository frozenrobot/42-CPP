#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed const & toCopy);
        Fixed &operator=(Fixed const &toAssign);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private:
        int _n;
        static const int fracBit = 8;
};

#endif
