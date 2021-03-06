// Exercise2-E.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>

class Dice 
{
	private:
		double rolled;
		double result;
	public:
		void initialize();
		double roll();
};

void Dice::initialize()
{
	rolled = 0;
	result = 0;
}
//ROLLS VIRTUAL DICE FOR NUMBERS BETWEEN 1 AND 10
double Dice::roll()
{
	rolled = (rand() % 10 + 1);
	result = rolled / 10;
	return result;
}
class Counter 
{
	private:
		int count;
	public:
		Counter(int n0 = 0);
		void increment();
		void reset();
		int getCount();

};
//CONSTRUCTOR
 Counter:: Counter(int n0)
 {
	 count = n0;
 }
 //FUNCTION THAT RETURN "count"
 int Counter::getCount()
 {
	 return count;
 }
 //FUNCTION FOR COUNTING TO 100
 void Counter::increment()
 {
	 if (count <= 100)
	 {
		 count++;
	 }

	 else
	 {
		 reset();
	 }
 }
 //RESETS COUNT
 void Counter::reset()
 {
	 count = 0;
 }
 //INSPECTOR CLASS FOR SETTING AND CHECKING LIMITS
class Inspector 
{
	private:
		double min;
		double max;
	public:
		void setLimits(double lower, double upper);
		bool isInLimits(double input);
};
//SETS LIMITS FOR DICE RESULT COUNT TO BE BETWEEN SPECIFIC AREAS
void Inspector::setLimits(double lower, double upper)
{
	min = lower;
	max = upper;
}
//CHECK IF THE ROLLED RESULTS ARE WITHIN THE LIMITS
bool Inspector::isInLimits(double input)
{
	if (input >= min && input <= max)
	{
		return true;
	}

	else
	{
		return false;
	}
}
int main()
{
	Dice dice;
	Counter counter1, counter2, i;
	Inspector inspector;
	srand(time(NULL));
	dice.initialize();
	counter1.reset(); counter2.reset(), i.reset();
	inspector.setLimits(0.0, 0.5);
	while (i.getCount() < 100) {
		if (inspector.isInLimits(dice.roll()))
			counter1.increment();
		else
			counter2.increment();
		i.increment();
	}
	std::cout << counter1.getCount() << std::endl;
	std::cout << counter2.getCount() << std::endl;
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
