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

/// \brief Represents a collection of an expanded object because it can represent it in hours, minutes, and seconds
using TimeRecord = struct
{
	int hours;
	int minutes;
	int seconds;
	bool is_before;
};

/// This is the main time object.
/// It is backed by a TimeRecord in order to have multiple representations
/// like Minutes, Hours, and Seconds
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

		/// Get the internal representation
		/// \return seconds
		int getSeconds()
		{
			return seconds;
		}

		/// Setter for internal representation
		/// \param seconds  seconds
		void setSeconds(int s) // not useful
		{
			this->seconds = s;
		}

		/// Adds two time objects together (this+other)
		/// \param other  The other time object to add from
		/// \return The time added together
		Time add(Time other) // adds two time objects together
		{
			return Time(this->seconds + other.seconds); // cascading??? just return a point back
		}

		/// Subtracts two time objects together (this-other). Additional checks are there to make
		/// sure the value never reaches negative
		/// \param other The other time object to add from
		/// \return  The time added together
		Time subtract(Time other) // subtracts two time objects. this - other
		{
			return Time(this->seconds - other.seconds);
		}

		/// Increases the time by a certain set amount of values
		/// \param h Hours
		/// \param m Minutes
		/// \param s Seconds
		/// \return A modified time with the increased quantities
		Time increaseBy(int h, int m, int s) // increase the time instance by a set quantity
		{
			return increaseBy(
					h * 3600 + m * 60 + s); // strips the individual hours, minutes down into seconds and then added.
		}

		/// Increases the Time using just seconds
		/// \param s Seconds to increase by
		/// \return The modified object
		/// \related increaseBy(int, int, int)
		Time increaseBy(int s)
		{
			return increaseBy(0, 0, s);
		}
};

/// \brief Generates the appropriate hours, minutes, and seconds from a time obj. Time only holds a singular unit of seconds to represent time!
/// \param obj The object in question
/// \return A record representing hours, minutes, seconds from the time object
static TimeRecord expandTime(Time obj)
{
	return {obj.getSeconds() / 3600, (obj.getSeconds() % 3600) / 60, obj.getSeconds() % 60, obj.getSeconds() < 0}; // basically we do what the constructor of the Time class did and separate the time back into components
}

///
/// \param record
/// \return
string formatRecord(TimeRecord record)
{
	// we make sure none of the time are negative so we can just append a final "-" at the beginning of the output

	string format;
	if(record.hours * 3600 + record.minutes * 60 + record.seconds < 0)
		format += "-";
	record.hours = abs(record.hours);
	record.minutes = abs(record.minutes);
	record.seconds = abs(record.seconds);
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

/// Asks the user to create a Time Object, this is basically the same askTimeRecord()
/// except that it returns a Time object instead of a Record
/// \return A created Time object
inline Time askTimeObj()
{
	gl("Create a Time Object:\n\t1. Just seconds\n\t2. Hours, minutes, and seconds\nEnter your option: ", int, time_select)
	Time timeObj {0}; // init to 0
	if (time_select == 1) // user select to enter in just seconds
	{
		gl("Enter seconds: ", int, userSeconds) // get userSeconds as just seconds
		timeObj = Time(userSeconds);
	} else if (time_select == 2) // user select to enter all accepted values
	{
		// all accepted values for input
		gl("Enter seconds: ", int, userSeconds)
		gl("Enter minutes: ", int, userMinutes)
		gl("Enter hours: ", int, userHours)
		timeObj = Time(userHours, userMinutes, userSeconds);
	}
	return timeObj;
}

/// Asks the user to create a Time Record and is mostly used for increaseBy
/// \return A created Time record
inline TimeRecord askTimeRecord()
{
	// prompt the user to enter for a time record, exactly like a TimeObj
	gl("Create a Time Record:\n\t1. Just seconds\n\t2. Hours, minutes, and seconds\nEnter your option: ", int, time_select)
	TimeRecord timeRecord;
	if (time_select == 1)
	{
		gl("Enter seconds: ", int, userSeconds) // get userSeconds as just seconds
		timeRecord = {0, 0, userSeconds}; // everything else is zero
	} else if (time_select == 2)
	{
		// all accepted values for input
		gl("Enter seconds: ", int, userSeconds)
		gl("Enter minutes: ", int, userMinutes)
		gl("Enter hours: ", int, userHours)
		timeRecord = {userHours, userMinutes, userSeconds}; // fill out all of the avaliable fields
	}
	return timeRecord;
}

#define LOOP for(;;) // macro for just a while(true) but less characters
// this macro is just something i used to test my code without having to spend hours going thru the user input and automating
// my testing process
#define bare_test(OBJ, AGAINST, MESSAGE) if(formatRecord(expandTime(OBJ))!=AGAINST){cout<<"[FAILED]\t"<<MESSAGE<<"\t"<<formatRecord(expandTime(OBJ));nl exit(-1);}else{cout<<"[PASSED]\t"<<MESSAGE<<"\t"<<formatRecord(expandTime(OBJ));nl}

int main(void)
{
	// unit tests - basically automated tests
	bare_test(Time(4, 40, 3), "04:40:03", "Test 1 for 4,30,3 -> 04:40:03")
	bare_test(Time(4, 0, 5).add(Time(18, 0, 5)), "22:00:10", "Test 2 for 4,0,5 + 18,0,5 = 22:00:10")
	bare_test(Time(12345678), "3429:21:18", "Test 3 this->seconds - other.seconds < 0 ? 0 : this->seconds - other.seconds for 12345678 -> HH:MM:SS")
	bare_test(Time(43).subtract(Time(43)), "00:00:00", "Test 4 for 43s-43s=0s")
	bare_test(Time(99).add(Time(83)), "00:03:02", "Test 5 for 99s+83s->HH:MM:SS")
	bare_test(Time(0, 60, 0), "01:00:00", "Test 6 for 60m->HH:MM:SS")
	bare_test(Time(400, 4, 0), "400:04:00", "Test 7 for 400,4,0->HH:MM:SS")
	bare_test(Time(59, 59, 59).add(Time(1)), "60:00:00", "Test 8 for 59,59,59+1s")
	bare_test(Time(99, 59, 59).add(Time(1)), "100:00:00", "Test 9 for  99,59,59+1s")
	bare_test(Time(0, 10, 0).subtract(Time(0, 30, 0)), "-00:20:00", "Test 10 for 0,10,0-0,30,0")
	nl
	nl
	nl
	// now we get input
	string n;
	LOOP
	{
		// first ask user to create a time object
		auto originalTime = askTimeObj();
		int operationOption = 0;
		LOOP
		{
			// continuously ask the user what they want to do
			nl
			sl("What do you want to do next?\n\t1-> Subtract from another time object\n\t2-> Add from another time object\n\t3-> Increase the time object\n\t4-> Display the current time object in HH:MM:SS format\n\tOther numbers. STOP\nEnter your choice: ", operationOption)
			if (operationOption == 1) // ask the user if they want to subtract from another time object
			{
				auto nowTime = askTimeObj(); // ask user to create another time object
				originalTime = originalTime.subtract(nowTime); // reassign it
				cout << "Subtracted time:   " << formatRecord(expandTime(originalTime))
					 << endl; // return the formatted string
			} else if (operationOption == 2) // add -> timeOKbj
			{
				auto nowTime = askTimeObj(); // ask user to create another time object
				originalTime = originalTime.add(nowTime); // reassign it
				cout << "Added time:   " << formatRecord(expandTime(originalTime))
					 << endl; // return the formatted string
			} else if (operationOption == 3) // increaseBy -> timeRecord
			{
				auto nowRecord = askTimeRecord(); // ask user to create another time record
				originalTime = originalTime.increaseBy(nowRecord.hours, nowRecord.minutes, nowRecord.seconds); // reassign it
				cout << "Increased time: " << formatRecord(expandTime(originalTime))
					 << endl; // return the formatted string
			} else if (operationOption == 4) // if the user just want to see the current time
				cout << "Current Time in HH:MM:SS format:\n" << formatRecord(expandTime(originalTime)) << endl;
			else break;
		}


		nl
		sl("Do another? (y/n): ", n)
		if (n != "Y" || n != "y") break;
	}
}
