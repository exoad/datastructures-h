/*
Write a program that asks the user
to input two Boolean values and
demonstrates the result of various
bitwise operators on them.
*/
#include <iostream>
using namespace std;
#define pg(STR,STORE) cout<<STR;cin>>STORE;cout<<endl;
#define out(expr) cout<<"Evaluates "<<(#expr)<<" is "<<(expr)<<endl;
int main(void)
{
    bool b1, b2;
    pg("Enter first boolean: ", b1)
    pg("Enter second boolean: ", b2)
    out(b1 & b2)
    out(b1 ^ b2)
    out(b1 | b2)
    out(~b1)
    out(~b2)
    out(b1 >> b2)
    out(b1 << b2)
}
