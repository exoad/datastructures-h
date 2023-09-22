/*
Write a program that accepts 5
integer values from the keyboard.
Store them in an array using a
pointer. Then print the array,
starting at the beginning of the array
and again starting at the end using
pointers.
*/

#include <iostream>

#define nl cout<<'\n';

using namespace std;

int main(void)
{
    int *i = new int[5];
    cout << "Enter #1: ";
    cin >> *i;
    i++;
    nl 
    cout << "Enter #2: ";
    cin >> *i;
    i++;
    nl
    cout << "Enter #3: ";
    cin >> *i;
    i++;
    nl
    cout << "Enter #4: ";
    cin >> *i;
    i++;
    nl
    cout << "Enter #5: ";
    cin >> *i;
    nl
    i -= 4;
    for(int j = 0; j < 5; j++, i++) cout << *i << " ";
    nl
    i -= 1;
    for(int j = 4; j >= 0; j--, i--) cout << *i << " ";
    
}