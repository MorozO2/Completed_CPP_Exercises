// Exercise7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "counter.h"
#include <iostream>
#pragma warning (disable:4996)

class LimitedCounter: public Counter
{

private:
	int limit;
public:

	LimitedCounter(int start, int lim);

	LimitedCounter &operator++();
	LimitedCounter operator++(int);
	~LimitedCounter();
};

//Constructor
LimitedCounter::LimitedCounter(int start, int lim): Counter(start), limit(lim) {}

//PREFIX
LimitedCounter& LimitedCounter::operator++()
{
	
	if (getCount() == limit)
	{
		return *this;
	}
		
	else
	{
		this->Counter::operator++();
		return *this;
	}
}
//POST-FIX
LimitedCounter LimitedCounter::operator++(int)
{
	LimitedCounter cnt(*this);

	if (getCount() == limit)
	{
		return cnt;
	}

	else
	{
		++(*this);
		return cnt;
	}
}

LimitedCounter::~LimitedCounter() { std::cout << "destructor done" << std::endl; };

int main()
{

	LimitedCounter lc(3, 5); //initial value 3, upper limit 5
	cout << lc++ << endl; //output should be 3
	std::cout << ++lc << endl; //output should be 5
	lc.reset();
	for (int i = 0; i < 9; i++) {
		lc++;
		cout << lc << endl; //output is 1 2 3 4 5 5 5 5 5
	}
	cout << lc.getCount() << endl; //output is 5
	cout << (lc < 7);//Testing the comparison operator //output is 1
	cout << (lc < 1);//Testing the comparison operator //output is 0
	return 0;
}

// Run program: Ctrl + F5 or Debug  Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
