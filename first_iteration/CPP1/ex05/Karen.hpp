#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>

class Karen
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        std::string identity[4];
    public:
        Karen(void);
        void complain( std::string level );
};

#endif