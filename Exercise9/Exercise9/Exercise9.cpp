// Exercise7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "counter.h"
#include <iostream>
#pragma warning (disable:4996)

class LimitedCounter : public Counter
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
LimitedCounter::LimitedCounter(int start, int lim) : Counter(start), limit(lim) {}

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

LimitedCounter::~LimitedCounter() { std::cout << "Limited destroyed" << std::endl; };


//ROUNDUP COUNTER
class RoundupCounter : public Counter
{
private:
	int limit;
public:
	RoundupCounter(int start, int lim);
	RoundupCounter &operator++();
	RoundupCounter operator++(int);
	~RoundupCounter();
};
//ROUNDUP CONSTRUCTOR
RoundupCounter::RoundupCounter(int start, int lmt) : Counter(start), limit(lmt) {};

RoundupCounter& RoundupCounter::operator++()
{
	if (getCount() > limit)
	{
		this->reset();
		this->Counter::operator++();
		return *this;
	}

	else
	{
		this->Counter::operator++();
		return *this;
	}
}

RoundupCounter RoundupCounter::operator++(int)
{
	RoundupCounter rcnt(*this);

	if (rcnt.getCount() > limit)
	{
		rcnt.reset();
		++(*this);
		return rcnt;
	}

	else
	{
		++(*this);
		return rcnt;
	}
}
//ROUNDUP DESTRUCTOR
RoundupCounter::~RoundupCounter() { std::cout << "Roundup destroyed" << std::endl; }

void UseCounter(Counter* cnt, int iter_num);

int main()
{

	LimitedCounter counterA(0, 5);   
	RoundupCounter counterB(0, 5);
	UseCounter(&counterA, 8); 
	UseCounter(&counterB, 8); 
	cout << "Counter A: " << counterA << endl;  // output should be 5    
	cout << "Counter B: " << counterB << endl;  // output should be 2
	return 0;
}

 void UseCounter(Counter* cnt, int iter_num)
{
	int i;
	for (i = 0; i < iter_num; i++)
	{
		cnt->operator++();
	}
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
