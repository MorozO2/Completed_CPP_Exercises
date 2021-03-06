// Exercise10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include <vector>
#pragma warning (disable: 4996)

int main()
{	
	//PART A
	std::cout << "Part A" << std::endl;
	std::pair <int, std::pair<std::string, std::string>> p1(123, std::make_pair ("aaaaa", "xxxxxx")), p2(345, std::make_pair("bbb", "yyy"));
	std::cout << p1.first << "		" << p1.second.first << "	" << (p1.second).second << std::endl;
	std::cout << p2.first << "		" << p2.second.first << "	" << (p2.second).second << "\n" <<std::endl;

	//PART B
	std::cout << "Part B" << std::endl;
	std::string element;
	std::string biggest;
	std::vector<std::string> str;

	//LOOP FOR FILLING OUT THE VECTOR
	while(element != "stop")
	{
		std::cin >> element;
		if (element != "stop")
		{
			str.push_back(element);
		}
	}
	std::cout << "\n";

	//LOOP ITERATES THROUGH THE VECTOR AND DISPLAY WHAT THE ITERATOR IS POINTING AT
	for (std::vector<std::string>::const_iterator n = str.begin(); n != str.end(); ++n) //USE AUTO
	{	
		std::cout << *n << std::endl;
		//COMPARE ELEMENT THAT N IS POINTING TO SIZE OF PREVIOUS ELEMENT, ASSIGN IT TO BIGGEST IF IT IS LARGER
		if (n->size() > biggest.size())
		{
			biggest = *n;
		}
	}

	std::cout << "\n";
	std::cout << "Size of vector " << str.size() << "\n"<<std::endl;
	std::cout << "The longest string is "<< biggest << std::endl;


	std::cout << "\n";
	std::cout << "vector.size(): "<< str.size() << std::endl; //SIZE() DISPLAYS HOW BIG (HOW MANY ELEMENTS) THE VECTOR IS
	std::cout << "sizeof(vector): "<< sizeof(str) << std::endl; //SIZEOF DISPLAYS THE SIZE OF MEMORY RESERVED FOR THE VECTOR ITSELF (2 POINTERS, 8 BYTES EACH)
	std::cout << "vector.capacity "<< str.capacity() << std::endl; //NUMBER OF SPACES RESERVED FOR THE VECTOR'S ELEMENTS
	
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
