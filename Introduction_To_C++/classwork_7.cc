/*
1. Write a function with a return
type of void that still helps the
caller calculate the area and
circumference of a circle when
supplied the radius. No print in
function.
2. Write overloaded functions that
calculate the volume of a sphere
and a cylinder.
*/

#include <iostream>
#include <cmath>

using namespace std;

#define nl cout << endl;
#define gl(STR,VAR) double VAR;     \
                    cout << STR; \
                    cin >> VAR;
#define sl(STR,VAR) cout << STR; \
                    cin >> VAR;

void areaofcircle(double &r, double &v)
{
    v = M_PI * r * r;
}

void circumference(double &r, double &v)
{
    v = 2 * M_PI * r;
}

void volume(double &r, double &v)
{
    v = 4.0/3.0 * M_PI * r * r * r;
}

void volume(double &r, double &h, double &v)
{
    v = M_PI * r * r * h;
}

int main(void)
{
    gl("Enter radius: ", radius)
    nl
    double v = 0;
    areaofcircle(radius, v);
    cout << "Area is " << v;
    nl
    circumference(radius, v);
    cout << "Circumference is " << v;
    nl
    gl("Enter cylinder height: ", cHeight)
    nl
    gl("Enter cylinder radius: ", cRadius)
    nl
    volume(radius, v);
    cout << "Volume of sphere: " << v;
    nl
    volume(cRadius, cHeight, v);
    cout << "Volume of cylinder: " << v;
}
