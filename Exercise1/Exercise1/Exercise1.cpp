// Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>

int arrMean(int *arr, int size);

int main()
{
	//INITIALIZE VARIABLES
	int num{ 0 }; //VARIABLE FOR USER INPUT
	int *n;		//POINTER FOR MEMORY ALLOCATION
	int i{ 0 }; //ITERATION THROUGH ARRAY

	std::cout << "How many numbers do you need?" << std::endl;
	std::cin >> num;
	
	n = new int[num]; //CREATES ARRAY FOR MEMORY ALLOCATION WITH POINTER n
	srand(time(NULL));

	std::cout << "\n";

	//FILLS OUT THE ARRAY WITH RANDOM NUMBERS
	for (i = 0; i < num; i++)
	{
		n[i] = rand() % 100;
		std::cout << n[i] << std::endl;
	}

	std::cout << "\n";

	//CALLS FUNCTION AND PRINTS OUT RESULT
	std::cout << arrMean(n, num);

	delete n;
	return 0;
}

//FUNCTION TAKES IN POINTER TO ARRAY AND SIZE OF ARRAY, CALCULATES MEAN
int arrMean(int *arr, int size)
{
	int i{ 0 };
	int sum{ 0 };

	for (i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	sum /= size;

	return sum;
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
