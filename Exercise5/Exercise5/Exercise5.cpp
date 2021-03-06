// Exercise4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#pragma warning (disable: 4996)

class String
{

private:

	char* str;
	int str_length;

public:

	String(const char ch[]);
	String(const String& string);
	const String& operator=(const String& newstr);
	const String operator+(const String& strl);
	String& operator++();
	String operator++(int);
	char& operator[](const int ind);
	operator const char*();
	~String();
	int length(const char arr[]);
	void list();
	friend std::ostream& operator<<(std::ostream& out, const String& strout);
};
//CONSTRUCTOR
String::String(const char ch[])
{
	str_length = length(ch);
	str = new char[str_length + 1]; //allocate according to length1
	strcpy(str, ch);
}
//COPY CONSTRUCTOR
String::String(const String& string)
{

	str = new char[length(string.str) + 1];
	strcpy(str, string.str);
}
//OVERLOADING = OPERATOR (HAS TO WORK SIMILAR TO CONSTRUCTOR)
const String& String::operator=(const String& strn)
{
	if (this != &strn)//SELF-CHECK
	{
		delete str;
		str = new char[length(strn.str) + 1];
		strcpy(str, strn.str);
	}
	return *this;
}
//OVERLOADING + OPERATOR
const String String::operator+(const String& strl)
{
	String sum(""); //CREATES LOCAL OBJECT
	delete sum.str; //DEALLOCATES MEMORY FOR THE ARRAY OF THAT OBJECT
	sum.str = new char[length(str) + length(strl.str) + 1]; //ALLOCATED NEW MEMORY IN ACCORADANCE WITH THE SIZE OF THE 2 STRINGS
	strcpy(sum.str, str);//COPIES THE LEFT SIDE TO THE ARRAY
	strcat(sum.str, strl.str);//CONCATINATES THE FIRST STRING WITH THE SECOND ONE
	return sum;	//RETURNS LOCAL VARIABLE
}
//OVERLOADING ++ (PRE) OPERATOR
String& String::operator++()
{
	String new_s(str);//CREATES LOCAL VARIABLE
	delete str;//DEALLOCATES THE MEMORY OF ARRAY IN LOCAL VARIABLE
	str = new char[length(new_s.str) + 2];//ALLOCATES NEW MEMORY IN ACCORADANCE WITH THE SIZE OF THE LEFT SIDE STRING + 2 (SPACE FOR NEW CHARACTER AND \0)
	strcpy(str, new_s.str);
	strcat(str, "X");
	return *this;
}
//OVERLOADING ++ (POST) OPERATOR
String String::operator++(int)
{
	String new_s(str);	//CREATES OBJECT TO HOLD THE ORIGINAL VALUE PASSED

	delete str;		//DEALLOCATES MEMORY FOR CURRENT STRING
	str = new char[length(new_s.str) + 2];	//ALLOCATES MEMORY FOR CONCATENATED STRING TO STR
	strcpy(str, new_s.str);	//COPIES ORIGINAL VALUE (FROM COPY) TO STR
	strcat(str, "X");	//CONCATENATES

	return new_s;	//RETURNS ORIGINAL VALUE, STR IS THE MODIFIED VALUE


}
//OVERLOADING [] OPERATOR
char& String::operator[](const int ind)
{
		return str[ind];
}
//CONVERSION TO C-STYLE STRING
String::operator const char*()
{
	return str;
}
//DESTRUCTOR
String::~String()
{
	std::cout << "destructor done" << std::endl;
	delete[] str;
}
//CALCULATES LENGTH OF STRING
int String::length(const char arr[])
{
	int length = 0;

	while (arr[length] != '\0')
	{
		length++;
	}

	return length;
}
void String::list()
{
	std::cout << str << std::endl;
}

void f(String s);


int main()
{

	String s("");
	char name[30];
	s = "Matti";
	std::cout << s << std::endl;
	strcpy(name, s);
	std::cout << name << std::endl;
}

void f(String s)
{
	s.list();
}
//OVERLOADED << OPERATOR
std::ostream& operator<<(std::ostream& out, const String& strout)
{
	out << strout.str;
	return out;
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
