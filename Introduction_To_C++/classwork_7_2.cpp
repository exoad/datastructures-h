/*
Write a function that accepts a
nonnegative integer from the user
and displays true in main if the
integer is a perfect number. The
function has no return and no print.
*/

#include <iostream>

using namespace std;

void is_perfect(int &v, bool &b)
{
    int s = 0;
    for(int i = 1; i < v; i++)
        if(v % i == 0) s += i;
    b = v == s;
}

int main(void)
{
    int val = 0;
    for(;;)
    {
        cout << "Enter a non-negative number: ";
        cin >> val;
        if(val < 0) cout << "Must be negative";
        else break;
    }
    bool b = true;
    is_perfect(val, b);
    cout << "\nIs perfect square: " << (b ? "true" : "false");
}