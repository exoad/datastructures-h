#include <iostream>

using namespace std;

// "new-line" This macro just prints a new line :/
#define nl cout << endl;
// "glue-line" This macro declares a variable and reads value into it from the console
#define gl(STR, TYPE, VAR) TYPE VAR;   \
                           cout << STR;\
                           cin >> VAR;
// "strip-line" This macro does not declare a variable and reads a pre-existing value from the console
#define sl(STR, VAR) cout << STR;\
                     cin >> VAR;
// This macro redefines a while(true)
#define LOOP for(;;)
// This macro is for user controlled exit
#define USER_LOOP(CODE) string ___USERE;                                    \
                        LOOP                                                \
                        {                                                   \
                              CODE;                                         \
                  		        nl                                            \
                  		        sl("Do another? (y/n): ", ___USERE)           \
                  		        if (___USERE != "Y" || ___USERE != "y") break;\
                        }

int main(void)
{
}
