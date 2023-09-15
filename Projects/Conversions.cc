/// \file Conversions.cc
/// \author Jack Meng
/// \brief Converts HEX and Integers between different bases
/// \date 2023-09-14

#include <iostream>
#include <cstring>

using namespace std;

// Funny macros, the first one prints a new line, the second one asks user for input and then
// reads what the user inputs. The third one is just for a shorthand way to write an inclusive range
#define nl cout<<endl;
#define gl(STR,VAR) cout<<STR;cin>>VAR;nl
#define rof(VAL,V1,V2) VAL>=V1&&VAL<=V2

/// \brief Represents the avaliable symbols for hex
constexpr const char* HEX = "0123456789ABCDEF";

/// \brief Converts the argument integer from base 10 to the argument base (base <= 9).
/// \param decimal The argument integer in base 10
/// \param base The target base that is base <= 9
/// \return string The converted target in a string format
string toBase(int decimal, int base)
{
    string res = "";

    while (decimal > 0)
    {
        int r = decimal % base;
        res = to_string(r) + res;
        decimal /= base;
    }

    return res;
}


/// \brief Converts the argument integer from base 10 to base 16.
/// \param decimal The argument integer in base 10
/// \return string The converted target in a string format
string toBase16(int decimal)
{
      string res = "";
      while(decimal > 0)
      {
            int r = decimal % 16;
            res = HEX[r] + res;
            decimal /= 16;
      }
      return res;
}


/// \brief Converts the argument string from the argument base to base 10 (base <= 9)
/// \param number The argument string in a supplied base
/// \param base The base of the argument number (parameter supplied)
/// \return int The converted argument in base 10
int toInteger(string number, int base)
{
      int res = 0;
      int p = 1;
      for(auto i = static_cast<int>(number.length() - 1); i >= 0; i--)
      {
            int val = number[i] - '0';

            if(val >= base || val < 0)
            {
                  cout << "Digit " << val << " not allowed for base " << base;
                  return -1;
            }
            res += val * p;
            p *= base;
      }
      return res;
}


/// \brief Converts hex to int
/// \param c A hex char
/// \return The specified int value
inline int htoi(char c)
{
      if(rof(c, '0', '9')) return c - '0';
      else if (rof(c, 'A', 'F')) return c - 'A' + 10;
      else if (rof(c, 'a', 'f')) return c - 'a' + 10;
      else
      {
            cout << "Digit " << c << " Not allowed in base 16";
            return -1;
      }
}

/// \brief Converts the argument string from base 16 to base 10
/// \param number The argument string in base 16
/// \return int The converted argument in base 10
/// \ref toInteger(string,int) "toInteger(number,16)"
int toInteger16(string number)
{
      int res = 0;
      int p = 1;
      for(auto i = static_cast<int>(number.length() - 1); i >= 0; i--)
      {
            int val = htoi(number[i]);
            if(val == -1) return -1;
            res += val * p;
            p *= 16;
      }
      return res;
}


int main(void)
{
      char r = 'n';
      for(;;) {
            cout << "Select an option:\n\t1 -> Convert integer from Base 10 to another base (base<=9)\n\t2 -> Convert integer from Base 10 to Base 16\n\t3 -> Convert a random based (base <= 9) value to base 10\n\t4 -> Convert HEX string from base 16 to base 10";
            nl
            int option = -1;
            for(;;)
            {
                  gl("Choice: ", option)
                  if(option >= 1 && option <= 4) break;
                  else cout << "Invalid choice (1,2,3,4) ";
            }
            if (option == 1)
            {
                  int b1 = 0;
                  int d1 = 0;
                  for(;;)
                  {
                        gl("Enter argument integer: ", d1)
                        gl("Enter argument base (where 2 <= base <= 9): ", b1)

                        if(rof(b1, 2, 9)) break;
                        else cout << "Invalid base, must be 2 <= base <= 9\n";
                  }
                  cout << "Result for " << d1 << ": Base 10 to Base  " << b1 << ": " << (d1 == 0 ? to_string(d1) : toBase(d1, b1)) << endl;
            }
            else if(option == 2)
            {
                  int d2;
                  gl("Enter argument integer: ", d2)
                  cout << "Result for " << d2 << ": Base 10 to Base 16: " << (d2 == 0 ? to_string(d2) : toBase16(d2)) << endl;
            }
            else if (option == 3)
            {
                  string n1 = "0";
                  int b2 = 0;
                  for(;;)
                  {
                        gl("Enter argument string: ", n1)
                        gl("Enter base (where base <= 9): ", b2)
                        if(rof(b2, 2, 9)) break;
                        else cout << "Invalid base, must be 2 <= base <= 9\n";
                  }
                  cout << "Result for " << n1 << ": Base " << b2 << " to Base 10: " << toInteger(n1, b2) << endl;
            }
            else
            {
                  string n2;
                  gl("Enter HEX string: ", n2)
                  cout << "Result for " << n2 << ": Base 16 to Base 10: " << toInteger16(n2) << endl;
            }
            nl
            gl("Convert another? (y/n): ", r)
            if(r == 'n' || r == 'N') break;
      }
}