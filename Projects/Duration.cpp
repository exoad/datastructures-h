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
     * @return Duration quotient of the two durations
     */
    Duration operator/(Duration const& other)
    {
      assert(other.totalSeconds!=0); // please dont do this :(
      return Duration(
        this->totalSeconds/other.totalSeconds
      );
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
    cout << (Duration(30, 60, 30)+Duration(30,30,30)); // 31:01:30+30:30:30=61:31:60=62:33:00
  })
}