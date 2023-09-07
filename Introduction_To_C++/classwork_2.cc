#include <iostream>

using namespace std;

/*
Write a program that creates
several integers. Ask the user
for the integers. Math them.
Display them.
*/

int main()
{
    int a, b, c, d;
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;
    cout << "Enter C: ";
    cin >> c;
    cout << "Enter D: ";
    cin >> d;
    
    cout << "\nA+B=" << (a+b) << "\nC*D=" << (c*d) << "\nIs A even? " << (!(a & 1) == 1 ? "True" : "False") << endl; 
}
