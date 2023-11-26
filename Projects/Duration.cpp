/**
 * @file Duration.cpp
 * @author Jack Meng
 * @brief Demonstrates adding durations and time together using operator overloading
 * @date 2023-11-26
 */

#include <iostream>
#include <cstring>
#include <cassert>

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

/**
 * @brief Makes sure the number is not negative [0, inf)
 *
 * @param i int
 * @return int i if i>=0 else 0
 */
inline int clampZero(int i)
{
  return i<0?0:i;
}

/**
 * @brief Uses two places for numbers less than 10
 *
 * @param i int
 * @return string "0"+i if i<10 else i
 */
inline string formatTwoSpaces(int i)
{
  return i<10?"0"+to_string(i):to_string(i);
}

/**
 * @brief A duration class that stores time in hours, minutes and seconds
 */
class Duration
{
  private:
  // private members
    int minutes = 0;
    int hours = 0;
    int seconds = 0;

    int totalSeconds;

  // private methods for computing total seconds and syncing time with the other attributes
    void computeTotalSeconds(int h, int m, int s)
    {
      totalSeconds=h*3600+m*60+s;
    }
  // syncing time with the other private members
    void syncTime()
    {
      hours=totalSeconds/3600;
      minutes=(totalSeconds%3600)/60;
      seconds=totalSeconds%60;
    }

  // private constructor for setting by total seconds (for internal use)
    Duration(int totalSeconds)
    {
      this->totalSeconds=totalSeconds;
      syncTime();
    }


  public:
    /**
     * @brief Construct a new Duration object
     *
     * @param h hours
     * @param m minutes
     * @param s seconds
     */
    Duration(int h, int m, int s)
    {
      computeTotalSeconds(
        clampZero(h),
        clampZero(m),
        clampZero(s)
      );
      syncTime();
    }

    /**
     * @brief Construct a new Duration object
     *
     * @param h hours
     * @param m minutes
     */
    Duration(int h, int m)
    {
      computeTotalSeconds(
        clampZero(h),
        clampZero(m),
        0
      );
      syncTime();
    }

    /**
     * @brief Construct a new Duration object
     *
     * @param h hours
     */
    Duration(int h)
    {
      computeTotalSeconds(
        h,
        0,
        0
      );
      syncTime();
    }

    /**
     * @brief Adds two durations
     *
     * @param other Duration
     * @return Duration sum of the two durations
     */
    Duration operator+(Duration const& other)
    {
      return Duration(
        this->totalSeconds+other.totalSeconds
      );
    }

    /**
     * @brief Subtracts two durations
     *
     * @param other Duration
     * @return Duration difference of the two durations
     */
    Duration operator-(Duration const& other)
    {
      return Duration(
        clampZero(this->totalSeconds-other.totalSeconds)
      );
    }

    /**
     * @brief Multiplies a duration by a constant
     *
     * @param other int
     * @return Duration product of the duration and the constant
     */
    Duration operator*(int const& other)
    {
      return Duration(
        this->minutes*other,
        this->hours*other,
        this->seconds*other
      );
    }

    /**
     * @brief Divides a duration by a constant
     *
     * @param other int
     * @return Duration quotient of the duration and the constant
     */
    Duration operator/(int const& other)
    {
      assert(other!=0); // please dont do this :(
      return Duration(
        this->minutes/other,
        this->hours/other,
        this->seconds/other
      );
    }

    /**
     * @brief Divides a duration by another duration
     *
     * @param other Duration
     * @return ratio of the two durations
     */
    double operator/(Duration const& other)
    {
      assert(other.totalSeconds!=0); // please dont do this :(
      return this->totalSeconds/other.totalSeconds;
    }

    /**
     * @brief For printing the duration in the format HH:MM:SS using the << operator (for cout)
     *
     * @param os ostream&
     * @param d Duration
     * @return ostream& os
     */
    friend ostream& operator<<(ostream& os, Duration const& d)
    {
      string format;
      if(d.hours<10)
        format+="0";
      format+=to_string(d.hours)+":";
      if(d.minutes<10)
        format+="0";
      format+=to_string(d.minutes)+":";
      if(d.seconds<10)
        format+="0";
      format+=to_string(d.seconds);
      os << format;
      return os;
    }

    /**
     * @brief Randomize the duration's time components
     */
    void randomize()
    {
      *this=Duration(
        rand()%24,
        rand()%60,
        rand()%60
      );
    }
};

/**
 * @brief Asks the user for the duration components
 *
 * @return Duration the duration object
 */
inline Duration askDurationObj()
{
  gl("Enter hours: ", int, hours)
  gl("Enter minutes: ", int, minutes)
  gl("Enter seconds: ", int, seconds)
  return Duration(minutes, hours, seconds);
}

int main(void)
{
  // ref: https://planetcalc.com/65/
  USER_LOOP({
    // ask the user for what they want
    gl("Options:"
       "\n\t1. Add two Duration objects"
       "\n\t2. Subtract two Duration objects"
       "\n\t3. Divide a Duration object by another to get the ratio"
       "\n\t4. Multiply a Duration object by a constant"
       "\n\t5. Divide a Duration object by a constant"
       "\n\t6. Print current Duration object"
       "\n\t7. Randomize the current Duration object"
       "\n\t8. Exit",
       int, option
    ) // get the option
    Duration original=askDurationObj();
    switch(option) // check against the possible options
    {
      case 1: // add two durations
      {
        Duration other=askDurationObj();
        cout << original << "+" << other << "=" << original+other;
        break;
      }
      case 2: // subtract two durations
      {
        Duration other=askDurationObj();
        cout << original << "-" << other << "=" << original-other;
        break;
      }
      case 3: // divide two durations
      {
        Duration other=askDurationObj();
        cout << original << "/" << other << "=" << original/other;
        break;
      }
      case 4: // multiply a duration by a constant
      {
        gl("Enter constant: ", int, constant)
        cout << original << "*" << constant << "=" << original*constant;
        break;
      }
      case 5: // divide a duration by a constant
      {
        gl("Enter constant: ", int, constant)
        cout << original << "/" << constant << "=" << original/constant;
        break;
      }
      case 6: // print the duration
      {
        cout << original;
        break;
      }
      case 7: // randomize the duration
      {
        original.randomize();
        cout << "Randomized: " << original;
        break;
      }
    }
  })
}