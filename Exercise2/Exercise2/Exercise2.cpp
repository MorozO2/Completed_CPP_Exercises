// Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Time
{
	private:
		int min, hr;

	public:
		void read(const char *ent);
		bool lessThan(Time tm);
		Time subtract(Time tm);
		void display();
};

//FUCNTION THAT READS USER INPUT FOR THE 2 TIMES BEING COMPARED
void Time::read(const char *ent)
{
	std::cout << ent << std::endl;
	std::cout << "Please enter hours:" << std::endl;
	std::cin >> hr;
	std::cout << "Please enter minutes:" << std::endl;
	std::cin >> min;
	
}
//FUNCTION THAT DETERMINES WHETHER THE OBJECT TIME AND MINUTE PROPERTIES ARE LESS THAT THE ONES OF THE PARAMETER PASSES
bool Time::lessThan(Time tm)
{
	if (hr < tm.hr || (hr == tm.hr && min < tm.min))
	{
		return true;
	}
	else 
	{
		return false;
	}
}
//SUBTRACTS THE 2 INPUTTED TIMES TO DETERMINE DURATION
Time Time::subtract(Time tm)
{
	Time duration;
	int min_dur{0};
	
	
	min_dur = (hr * 60 + min) - (tm.hr * 60 + tm.min);
	duration.hr = min_dur / 60;
	duration.min = min_dur % 60;
	
	
	return duration;
}
//DISPLAYS THE TIME AND MINUTES PROPERTIES OF A GIVEN OBJECT
void Time::display()
{
	std::cout << hr;
	std::cout << ":";
	std::cout << min << std::endl;
}

int main()
{
	char ent_1[] = { "Enter time 1" };
	char ent_2[] = { "Enter time 2" };
	const char *ent1 = ent_1;
	const char *ent2 = ent_2;
	Time time1, time2, duration;

	
	time1.read(ent1);
	time2.read(ent2);
	time1.display();
	time2.display();
	if (time1.lessThan(time2)) {
		duration = time2.subtract(time1);
		std::cout << "Starting time was ";
		time1.display();
	}
	else {
		duration = time1.subtract(time2);
		std::cout << "Starting time was ";
		time2.display();
	}
	std::cout << "Duration was ";
	duration.display();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
