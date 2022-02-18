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
        virtual ~Fixed();
        Fixed &operator=(Fixed const & toAssign);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;


        bool operator>(Fixed const & instance) const;    
        bool operator<(Fixed const & instance) const;    
        bool operator>=(Fixed const & instance) const;    
        bool operator<=(Fixed const & instance) const;    
        bool operator==(Fixed const & instance) const;    
        bool operator!=(Fixed const & instance) const;
        
        Fixed operator+(Fixed const & instance) const;
        Fixed operator-(Fixed const & instance) const;
        Fixed operator*(Fixed const & instance) const;
        Fixed operator/(Fixed const & instance) const;

        Fixed & operator++(void);
        Fixed operator++(int);
        Fixed & operator--(void);
        Fixed operator--(int);

        static Fixed &min(Fixed &u, Fixed &v);
        const static Fixed &min(const Fixed &u, const Fixed &v);
        static Fixed &max(Fixed &u, Fixed &v);
        const static Fixed &max(const Fixed &u, const Fixed &v);
    
    private:
        int _n;
        static const int fracBit = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &instance);

#endif