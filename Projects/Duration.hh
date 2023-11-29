#pragma once
#include <iostream>
using namespace std;

class Duration
{
    public:
        Duration(int h, int m, int s);
        Duration(int h, int m);
        Duration(int h);
        Duration operator+(Duration const&);
        Duration operator-(Duration const&);
        Duration operator*(int const&);
        Duration operator/(int const&);
        friend ostream& operator<<(ostream&, Duration const&);
        void randomize();
};
