// Exercise3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#pragma warning (disable: 4996)




class String
{

private:

	char* str;
	
public:
	
	String(const char ch[11]);
	String(const String& string);
	~String();
	void list();

};
String::String(const char ch[11])
{
	str = new char[11];
	strcpy(str, ch);
}

String::String(const String& string)
{
	
	str = new char[11];
	strcpy(str, string.str);
}

String::~String()
{
	std::cout << "destructor done" << std::endl;
	delete[] str;
}

void String::list()
{
	std::cout << str << std::endl;

}

void f(String s);


int main()
{
	String s("abcdefg");
	s.list();
	f(s);
	s.list();

}

void f(String s)
{
	s.list();
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
