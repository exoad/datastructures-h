/// \file TimeTrack.cc
/// \author Jack Meng
/// \brief A program to keep track of time and modify time
/// \date 2023-10-5

#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>

// This macro just prints a new line :/
#define nl cout << endl;
// This macro declares a variable and reads value into it from the console
#define gl(STR, TYPE, VAR) TYPE VAR;    \
                          cout << STR;\
                          cin >> VAR;
// This macro does not declare a variable and reads a pre-existing value from the console
#define sl(STR, VAR) cout << STR;      \
                    cin >> VAR;
using namespace std;

/// @brief Represents a collection of an expanded object because it can represent it in hours, minutes, and seconds
using TimeRecord = struct
{
	int hours;
	int minutes;
	int seconds;
};

#define clamp_time(val) val<0?0:val

class Time
{
	private:
		int seconds; // singular unit, easier to work with, might overflow though (int64_t!)

	public:
		explicit Time(int s) : seconds(clamp_time(s))
		{
		}

		Time(int h, int m, int s) : seconds(clamp_time(h * 3600 + m * 60 + s))
		{
		}

		int getSeconds()
		{
			return seconds;
		}

		Time add(Time other) // adds two time objects together
		{
			return Time(this->seconds + other.seconds); // cascading??? just return a point back
		}

		Time subtract(Time other) // subtracts two time objects. this - other
		{
			return Time(clamp_time(this->seconds - other.seconds));
		}

		Time increaseBy(int h, int m, int s) // increase the time instance by a set quantity
		{
			return increaseBy(
					h * 3600 + m * 60 + s); // strips the individual hours, minutes down into seconds and then added.
		}

		Time increaseBy(int s)
		{
			return Time(this->seconds + s);
		}

		/// Setter for the hours param
		/// \param h Overwrites the current with this parameter
		void setHour(int h)
		{
			this->seconds = h * 3600; // sets the current time in seconds to a given hours unit (converted)
		}

		/// Setter for the seconds param
		/// \param s Overwrites the current time with this parameter
		void setSecond(int s)
		{
			this->seconds = s; // sets the current time to a new seconds value
		}

		void setMinute(int m)
		{
			this->seconds = m * 60; // sets the current time to a new minutes value (converted)
		}

};

/// \brief Generates the appropriate hours, minutes, and seconds from a time obj. Time only holds a singular unit of seconds to represent time!
/// \param obj The object in question
/// \return A record representing hours, minutes, seconds from the time object
static TimeRecord expandTime(Time obj)
{
	return {obj.getSeconds() / 3600, (obj.getSeconds() % 3600) / 60, obj.getSeconds() %
																	 60}; // basically we do what the constructor of the Time class did and separate the time back into components
}

///
/// \param record
/// \return
string formatRecord(TimeRecord record)
{
	string format;
	if (record.hours < 10) // if we need to use more than a single digit for the hour's place
		format += "0";
	format += to_string(record.hours) + ":";
	if (record.minutes < 10) // if we need to use more than a single digit for the minute's place
		format += "0";
	format += to_string(record.minutes) + ":";
	if (record.seconds < 10) // if we need to use more than a single digit for the second's place
		format += "0";
	format += to_string(record.seconds);
	return format;
}

Time askTimeObj()
{
	gl("Create a Time Object:\n\t1. Just seconds\n\t2. Hours, minutes, and seconds\nEnter your option: ", int, time_select)
	Time timeObj {0};
	if (time_select == 1) // user select to enter in just seconds
	{
		gl("Enter seconds: ", int, userSeconds)
		timeObj = Time(userSeconds);
	} else if (time_select == 2) // user select to enter all accepted values
	{
		gl("Enter seconds: ", int, userSeconds)
		gl("Enter minutes: ", int, userMinutes)
		gl("Enter hours: ", int, userHours)

		timeObj = Time(userHours, userMinutes, userSeconds);
	}
	return timeObj;
}

#define test(CONDITION, MESSAGE) if(!(CONDITION)){cout<<"[FAILED]\t"<<MESSAGE;nl exit(-1);}else{cout<<"[PASSED]\t"<<MESSAGE;nl}
#define bare_test(OBJ, AGAINST, MESSAGE) if(formatRecord(expandTime(OBJ))!=AGAINST){cout<<"[FAILED]\t"<<MESSAGE<<"\t"<<formatRecord(expandTime(OBJ));nl exit(-1);}else{cout<<"[PASSED]\t"<<MESSAGE<<"\t"<<formatRecord(expandTime(OBJ));nl}

int main(void)
{
	bare_test(Time(4, 40, 3), "04:40:03", "Test 1 for 4,30,3 -> 04:40:03")
	bare_test(Time(4, 0, 5).add(Time(18, 0, 5)), "22:00:10", "Test 2 for 4,0,5 + 18,0,5 = 22:00:10")
	bare_test(Time(12345678), "3429:21:18", "Test 3 this->seconds - other.seconds < 0 ? 0 : this->seconds - other.seconds for 12345678 -> HH:MM:SS")
	bare_test(Time(43).subtract(Time(43)), "00:00:00", "Test 4 for 43s-43s=0s")
	bare_test(Time(99).add(Time(83)), "00:03:02", "Test 5 for 99s+83s->HH:MM:SS")
	bare_test(Time(0, 60, 0), "01:00:00", "Test 6 for 60m->HH:MM:SS")
	bare_test(Time(400, 4, 0), "400:04:00", "Test 7 for 400,4,0->HH:MM:SS")
	/*
	string n;
	for(;;)
	{
		auto originalTime = askTimeObj();
		int operationOption = 0;
		for(;;)
		{
			nl
			sl("What do you want to do next?\n\t1-> Subtract from another time object\n\t2-> Add from another time object\n\t3-> Increase the time object by (Hours, Minutes, Seconds)\n\t4-> Increase the time by seconds\n\t5-> Display the current time object in HH:MM:SS format\n\tOther numbers. STOP\nEnter your choice: ", operationOption)
			if(operationOption == 1)
			{

			}
			else if(operationOption == 2)
			{

			}
			else if(operationOption == 3)
			{

			}
			else if (operationOption == 4)
			{

			}
			else if(operationOption == 5)
				cout << "Current Time in HH:MM:SS format:\n" << formatRecord(expandTime(originalTime)) << endl;
			else break;
		}


		nl
		sl("Do another? (y/n): ", n)
		if(n != "Y" || n != "y") break;
	}
	*/
}