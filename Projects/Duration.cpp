#include <iostream>

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

using namespace std;

inline int clampZero(int i)
{
  return i<0?0:i;
}

class Duration
{
  private:
    int minutes;
    int hours;
    int seconds;

    int totalSeconds()
    {
      return seconds + minutes * 60 + hours * 3600;
    }

  public:
    Duration(int m = 0, int h = 0, int s = 0) : minutes(m), hours(h), seconds(s) {}

    Duration operator+(Duration const& other)
    {
      return Duration(
        this->minutes+other.minutes,
        this->hours+other.hours,
        this->seconds+other.seconds
      );
    }

    Duration operator-(Duration const& other)
    {
      return Duration(
        clampZero(this->minutes-other.minutes),
        clampZero(this->hours-other.hours),
        clampZero(this->seconds-other.seconds)
      );
    }

    Duration operator*(int const& other)
    {
      return Duration(
        this->minutes*other,
        this->hours*other,
        this->seconds*other
      );
    }

    Duration operator/(int const& other)
    {
      return Duration(
        this->minutes/other,
        this->hours/other,
        this->seconds/other
      );
    }

    Duration operator/(Duration const& other)
    {
      return Duration(
        this->minutes/other.minutes,
        this->hours/other.hours,
        this->seconds/other.seconds
      );
    }

    friend ostream& operator<<(ostream& os, Duration const& d)
    {
      os << d.hours << ":" << d.minutes << ":" << d.seconds;
      return os;
    }

    void randomize()
    {
      // not going to use the facilities in random.h even though they have better randomness :P
      this->minutes = rand() % 60;
      this->hours = rand() % 24;
      this->seconds = rand() % 60;
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
  USER_LOOP({

  })
}