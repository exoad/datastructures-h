/// \file TimeTrack.cc
/// \author Jack Meng
/// \brief A program to keep track of time and modify time
/// \date 2023-10-5

#include <iostream>
#include <cstring>
#include <cassert>

// This macro just prints a new line :/
#define nl cout << endl;
// This macro declares a variable and reads value into it from the console
#define gl(STR,TYPE,VAR) TYPE VAR;    \
                          cout << STR;\
                          cin >> VAR;
// This macro does not declare a variable and reads a pre-existing value from the console
#define sl(STR,VAR) cout << STR;      \
                    cin >> VAR;

using namespace std;

using TimeRecord = struct
{
	int hours;
	int minutes;
	int seconds;
};

class Time
{
	private:
		int seconds; // singular unit, easier to work with, might overflow though (int64_t!)

	public:
		explicit Time(int s) : seconds(s)
		{
		}

		Time(int h, int m, int s) : seconds(h * 3600 + m * 60 + s)
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
			return Time(this->seconds - other.seconds);
		}

		Time increaseBy(int h, int m, int s) // increase the time instance by a set quantity
		{

		}

		Time increaseBy(int s)
		{

		}

		void setHour(int h)
		{
			this->seconds = h * 3600; // sets the current time in seconds to a given hours unit (converted)
		}

		void setSecond(int s)
		{
			this->seconds = s; // sets the current time to a new seconds value
		}

		void setMinute(int m)
		{
			this->seconds = m * 60; // sets the current time to a new minutes value (converted)
		}

};

/// @brief Generates the appropriate hours, minutes, and seconds from a time obj. Time only holds a singular unit of seconds to represent time!
/// @param obj The object in question
/// @return A record representing hours, minutes, seconds from the time object
TimeRecord expandTime(Time obj)
{
	return {obj.getSeconds() / 3600, (obj.getSeconds() % 3600) / 60, obj.getSeconds() % 60}; // basically we do what the constructor of the Time class did and separate the time back into components
}

string formatRecord(TimeRecord record)
{
	string format = "";
	if(record.hours < 10)
		format += "0";
	format += to_string(record.hours) + ":";
	if(record.minutes < 10)
		format += "0";
	format += to_string(record.minutes) + ":";
	if(record.seconds < 10)
		format += "0";
	format += to_string(record.seconds);
	return format;
}

Time askTimeObj()
{
	gl("Create a Time Object:\n\t1. Just seconds\n\t2. Hours, minutes, and seconds\nEnter your option: ", int, time_select)
	Time timeObj{0};
	if(time_select == 1) // user select to enter in just seconds
	{
		gl("Enter seconds: ", int, userSeconds)
		timeObj = Time(userSeconds);
	}
	else if(time_select == 2) // user select to enter all accepted values
	{
		gl("Enter seconds: ", int, userSeconds)
		gl("Enter minutes: ", int, userMinutes)
		gl("Enter hours: ", int, userHours)

		timeObj = Time(userHours, userMinutes, userSeconds);
	}
	return timeObj;
}

#define test(CONDITION, MESSAGE) if(!(CONDITION)){cout<<"[FAILED]\t"<<MESSAGE;nl exit(-1);}else{cout<<"[PASSED]\t"<<MESSAGE;nl}

int main(void)
{
	test(formatRecord(expandTime(Time(4343))) == "01:12:23", "Test 1 for 4343s -> HH:MM:SS")
	test(formatRecord(expandTime(Time(43))) == "00:00:43", "Test 2 for 43s -> HH:MM:SS")
	test(formatRecord(expandTime(Time(4343).subtract(Time(4343)))) == "00:00:00", "Test 3 for 4343s-4343s")
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