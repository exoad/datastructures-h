/// \file PointerFunctions.cc
/// \author Jack Meng
/// \brief Does stuffs according to the assignment sheet
/// \date 2023-09-28

#include <iostream>
#include <cstring>

using namespace std;

#define nl cout << endl;
#define gl(STR,TYPE,VAR) TYPE VAR;    \
                          cout << STR;\
                          cin >> VAR;
#define sl(STR,VAR) cout << STR;      \
                    cin >> VAR;

/// @brief This function swaps two integers using pointers.
/// @param a The first integer
/// @param b The second integer
void swap(int *a, int *b) // noexcept // comment this out for my own compiler
{
      int temp = *a;
      *a = *b;
      *b = temp;
}

/// @brief This function counts the number of both vowels and consonants in a given string.
/// @param s The input string
/// @param numVowels The number of vowels in the string
/// @param numConsonants The number of consonants in the string
void letterCount(string s, int *numVowels, int *numConsonants)
{
      *numVowels = 0;
      *numConsonants = 0;
      const char* ptr = s.c_str();
      while (*ptr)
      {
            if (*ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U') (*numVowels)++;
            else (*numConsonants)++;
            ptr++;
      }
}

/// @brief This function accepts a pointer that refers to the first element of an array of length elements. This
/// function will display each element and its memory location. The information for each element must be
/// on a new line, with the element and memory location separated by a single space.
/// @param arrPtr The array
/// @param length The length of the array
void arrayInfo(int *arrPtr, int length) // const *
{
      for(int i = 0; i < length; i++)
            cout << "Element " << i << " Value=" << arrPtr[i] << " Memory Location=" << &arrPtr[i] << '\n';
}

/// @brief User interaction happens here. Entry point into the PointerFunctions program
int main(void)
{
      string n;
      for(;;)
      {
            gl("Select an operation:\n\t1. Swap two integers using pointers\n\t2. Count number of vowels and consonants\n\t3. Get array info.\nEnter option: ", int, option)
            if(option == 1)
            {
                  gl("Enter first number: ", int, a)
                  gl("Enter second number: ", int, b)
                  swap(&a, &b);
                  cout << "First number: " << a;
                  nl
                  cout << "Second number: " << b;
            }
            else if (option == 2)
            {
                  gl("Enter string: ", string, str)
                  int numVowels = 0;
                  int numConsonants = 0;
                  letterCount(str, &numVowels, &numConsonants);
                  cout << "Number of vowels: " << numVowels;
                  nl
                  cout << "Number of consonants: " << numConsonants;
            }
            else if (option == 3)
            {
                  gl("Enter length of array: ", int, len)
                  auto arr = new int[len];
                  for(int i = 0; i < len; i++)
                  {
                        sl("Enter element " + to_string(i) + " : ", arr[i])
                  }
                  arrayInfo(arr, len);
                  delete[] arr;
            }
            nl
            sl("Do another? (y/n): ", n)
            if(n != "Y" || n != "y") break;
      }
}