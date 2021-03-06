// Exercise 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <time.h>

void printwin(int win);

class RandGen_2 {
public:
	RandGen_2() : numbers() { srand(time(NULL)); }
	int operator()();
private:
	std::vector<int> numbers;
};

int main(void) {
	std::vector<int> numbers(7); //VECTOR FOR WINNING NUMBERS
	std::vector<int> drawn(7);	//VECTOR FOR NUMBERS DRAWN
	std::vector<int> wins;	//VECTOR FOR DRAWN NUMBERS THAT MATCH WINNING NUMBERS
	std::ostream_iterator<int> out_p(std::cout, "	");//ITERATOR TO PRINT NUMBERS

	//GENERATES NUMBERS
	RandGen_2 randGen_2;
	std::generate(numbers.begin(), numbers.end(), randGen_2);
	std::generate(drawn.begin(), drawn.end(), randGen_2);

	//PRINTS OUT THE 2 ROWS OF NUMBERS
	std::copy(numbers.begin(), numbers.end(), out_p);
	std::cout << "\n";
	std::copy(drawn.begin(), drawn.end(), out_p);
	std::cout << "\n";

	//SORT THE 2 VECTORS IN ORDER TO COMPARE WITH set_intersection
	std::sort(numbers.begin(), numbers.end());
	std::sort(drawn.begin(), drawn.end());

	//COMPARES THE 2 VECTORS AND PUT THE MATCHING NUMBERS INTO wins VECTOR
	std::set_intersection(numbers.begin(), numbers.end(), drawn.begin(), drawn.end(), std::back_inserter(wins)); //BACK INSERTER IS AN ITERATOR (REQUIRED BY set_intersection)

	//PRINTS OUT THE WINNING NUMBERS
	std::cout << "\n";
	std::cout << "Winning numbers:" << std::endl;
	std::for_each(wins.begin(), wins.end(), printwin);
}

int RandGen_2::operator()() {
	int number;
	do {
		number = rand() % 37 + 1;
	} while (find(numbers.begin(), numbers.end(), number) != numbers.end());
	numbers.push_back(number);
	return number;
}

void printwin(int win)
{
	static int j = 0;
	std::cout << "#" << ++j << "  " << win << std::endl;
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
