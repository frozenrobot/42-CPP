#include "iter.hpp"

template < typename T >
void iter(T *array, size_t length, void (*func)(T &elem))
{
    for (size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

template < typename T >
void output(T &elem)
{
    std::cout << elem << std::endl;
}

template < typename T >
void flip(T &elem)
{
    elem = (elem == 0);
}



class Awesome

{

public:
Awesome ( void) : _n( 42 ) { return; } 
int get( void) const { return this->_n; } 
private: int _n;

}; std::ostream & operator<<( std::ostream & o, Awesome const & rhs) {o << rhs.get();

return o; }

template< typename T >
void print(T & x) { std::cout << x << std::endl; return; } 


int main(void)
{
    float floatarray[3] = {1.5, 2.7, 3.1};
    iter<float>(floatarray, 3, &output);
    std::string strarray[3] = {"one", "two", "three"};
    iter<std::string>(strarray, 3, &output);
    bool boolarray[2] = {true, false};
    iter<bool>(boolarray, 2, &output);
    iter<bool>(boolarray, 2, &flip);
    iter<bool>(boolarray, 2, &output);

    int tab[] = {0,1,2,3,4};
    Awesome tab2[5];
    iter(tab, 5, print);
    iter(tab2, 5, print);
}
