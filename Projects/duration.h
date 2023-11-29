#pragma once
#include <iostream>
#include <cassert>
using namespace std;

class Duration
{
    int hours, minutes, seconds;
    int computeTotalSeconds() const;
    public:
        Duration(int h, int m, int s);
        Duration(int h, int m);
        Duration(int h);
        Duration operator+(Duration const&);
        Duration operator-(Duration const&);
        Duration operator*(int const&);
        Duration operator/(int const&);
        double operator/(Duration const&);
        friend ostream& operator<<(ostream& os, Duration const& other);
        void randomize();
};

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
    int Duration::computeTotalSeconds() const
    {
      return Duration::hours*3600+Duration::minutes*60+Duration::seconds;
    }

    /**
     * @brief Construct a new Duration object
     *
     * @param h hours
     * @param m minutes
     * @param s seconds
     */
    Duration::Duration(int h, int m, int s) : hours(h), minutes(h), seconds(s)
    {
    }

    /**
     * @brief Construct a new Duration object
     *
     * @param h hours
     * @param m minutes
     */
    Duration::Duration(int h, int m) : hours(h), minutes(h), seconds(0)
    {
    }

    /**
     * @brief Construct a new Duration object
     *
     * @param h hours
     */
    Duration::Duration(int h) : hours(h), minutes(0), seconds(0)
    {
    }

    /**
     * @brief Adds two durations
     *
     * @param other Duration
     * @return Duration sum of the two durations
     */
    Duration Duration::operator+(Duration const& other)
    {
      int totalSeconds=Duration::computeTotalSeconds()+other.computeTotalSeconds();
      return Duration(
        totalSeconds/3600,
        (totalSeconds%3600)/60,
        totalSeconds%60
      );
    }

    /**
     * @brief Subtracts two durations
     *
     * @param other Duration
     * @return Duration difference of the two durations
     */
    Duration Duration::operator-(Duration const& other)
    {
      int totalSeconds=this->computeTotalSeconds()-other.computeTotalSeconds();
      return Duration(
        totalSeconds/3600,
        (totalSeconds%3600)/60,
        totalSeconds%60
      );
    }

    /**
     * @brief Multiplies a duration by a constant
     *
     * @param other int
     * @return Duration product of the duration and the constant
     */
    Duration Duration::operator*(int const& other)
    {
      return Duration(
        Duration::minutes*other,
        Duration::hours*other,
        Duration::seconds*other
      );
    }

    /**
     * @brief Divides a duration by a constant
     *
     * @param other int
     * @return Duration quotient of the duration and the constant
     */
    Duration Duration::operator/(int const& other)
    {
      assert(other!=0); // please dont do this :(
      return Duration(
        Duration::minutes/other,
        Duration::hours/other,
        Duration::seconds/other
      );
    }

    /**
     * @brief Divides a duration by another duration
     *
     * @param other Duration
     * @return ratio of the two durations
     */
    double Duration::operator/(Duration const& other)
    {
      return (double)Duration::computeTotalSeconds()/other.computeTotalSeconds();
    }

    /**
     * @brief For printing the duration in the format HH:MM:SS using the << operator (for cout)
     *
     * @param os ostream&
     * @param d Duration
     * @return ostream& os
     */
    ostream& operator<<(ostream& os, Duration const& d)
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
    void Duration::randomize()
    {
      *this=Duration(
        rand()%24,
        rand()%60,
        rand()%60
      );
    }
