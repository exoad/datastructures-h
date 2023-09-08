/*
Write a program that
demonstrates that the size of an
unsigned integer and a normal
integer are the same, and that
both are smaller in size than a
long integer (and long long if
you’d like).

Write a program to calculate the
area and circumference of a
circle, where the user supplies
the radius.
*/

#include <iostream>
#include <cmath>
using namespace std;

#define eval(type) #type<<":"<<sizeof(type)
#define nl cout<<'\n';

int main() 
{
    cout << eval(int) << " == " << eval(unsigned int) << '\n' << eval(int) << " and " << eval(unsigned int) << " < " << eval(long int) << " and " << eval(long long) << endl;
    
    double radius;
    cout << "Enter radius: ";
    cin >> radius;
    nl
    cout << "Area of circle: " << (M_PI * (radius * radius)) << "\nCircumference of circle: " << (2 * M_PI * radius) << endl; 
}
