#ifndef NUMBER_HPP
#define NUMBER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <cctype>

class Number
{
    private:
        std::string str;
        int type;           //type 1=char, 2=int, 3=double, 4=float, 0=invalid
        char aschar;
        int asint;
        double asdouble;
        float asfloat;
        int flags[4]; //constructor sets to 0; 
        void parse(void);
        void convert(void);
        void setFlag(int type, int flag);
        int getFlag(int type);
        bool hasFlag(int type, int flag);
    public:
        Number(std::string input);
        ~Number();
        void outputInfo(void);
};



#endif