/// \file PointerFunctions.cc
/// \author Jack Meng
/// \brief Does stuffs according to the assignment sheet
/// \date 2023-09-28

#include <iostream>

using namespace std;

#define nl cout << endl;
#define gl(STR,VAR) int VAR;    \
                    cout << STR;\
                    cin >> VAR;
#define sl(STR,VAR) cout << STR;\
                    cin >> VAR;

int main(void)
{
      string n;
      for(;;)
      {
            gl("Select an operation:\n\t1. Swap two integers using pointers\n\t2. Count number of vowels and consonants\n\t3. Get array info.\nEnter option: ", option)
            if(option == 1)
            {

            }
            else if (option == 2)
            {

            }
            else if (option == 3)
            {

            }
            else
            {

            }

            nl
            sl("Do another? (y/n): ", n)
            if(n == "N" || n == "n") break;
      }
}