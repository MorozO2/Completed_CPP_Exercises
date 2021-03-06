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
	const int MAX_STRING_LENGTH = 10;
	static int counter;
	
	
public:

	

	String();
	String(const char ch[]);
	String(const String& string);
	const String& operator=(const String& newstr);
	String operator+(const String& strl) const;
	String& operator++();
	String operator++(int);
	char& operator[](const int ind);
	operator const char*();
	~String();
	int length(const char arr[]) const;
	void list();

	static void display_count() { std::cout << counter << std::endl; };

	friend std::ostream& operator<<(std::ostream& out, const String& strout);

};

int String::counter = 0;

//DEFAULT CONSTRUCTOR
String::String() { counter++; };

//CONSTRUCTOR
	String::String(const char ch[])
	{
		counter++;

		str_length = length(ch) + 1;

		if (str_length > MAX_STRING_LENGTH)
		{
			str = new char[MAX_STRING_LENGTH + 1]; //allocate according to MAX_STRING_LENGTH
			strncpy(str, ch, MAX_STRING_LENGTH);
			str[MAX_STRING_LENGTH] = '\0';
		}
		else
		{
			str = new char[str_length + 1]; //allocate according to length1
			strcpy(str, ch);
		}

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
	String String::operator+(const String& strl) const
	{
		
		String sum; //REATES LOCAL OBJECT
		delete sum.str; //DEALLOCATES MEMORY FOR THE ARRAY OF THAT OBJECT
		int length = strl.length(str) + this->length(str) + 1;
		if (length > MAX_STRING_LENGTH)
		{
			sum.str = new char[MAX_STRING_LENGTH+1];
			strncpy(sum.str, str, MAX_STRING_LENGTH);
			strncat(sum.str, strl.str, MAX_STRING_LENGTH);
			sum.str[MAX_STRING_LENGTH] = '\0';
			return sum;
		}
		else
		{
			sum.str = new char[length];//ALLOCATED NEW MEMORY IN ACCORADANCE WITH THE SIZE OF THE 2 STRINGS
			strcpy(sum.str, str);//COPIES THE LEFT SIDE TO THE ARRAY
			strcat(sum.str, strl.str);//CONCATINATES THE FIRST STRING WITH THE SECOND ONE
			return sum;	//RETURNS LOCAL VARIABLE
		}
		
		
	}
	//OVERLOADING ++ (PRE) OPERATOR
	String& String::operator++()
	{
		String new_s(str);//CREATES LOCAL VARIABLE
		delete str;//DEALLOCATES THE MEMORY OF ARRAY IN LOCAL VARIABLE
		str_length = length(new_s.str) + 2;
		if (str_length > MAX_STRING_LENGTH)
		{
			str = new char[MAX_STRING_LENGTH + 1];
			strncpy(str, new_s.str, MAX_STRING_LENGTH);
			//strncat(str, "X", MAX_STRING_LENGTH);
			str[MAX_STRING_LENGTH] = '\0';
			return *this;
		}
		else 
		{
			str = new char[str_length];//ALLOCATES NEW MEMORY IN ACCORADANCE WITH THE SIZE OF THE LEFT SIDE STRING + 2 (SPACE FOR NEW CHARACTER AND \0)
			strcpy(str, new_s.str);
			strcat(str, "X");
			return *this;
		}
		
	}
	//OVERLOADING ++ (POST) OPERATOR
	String String::operator++(int)
	{
		String new_s(str);	//CREATES OBJECT TO HOLD THE ORIGINAL VALUE PASSED
		delete str;		//DEALLOCATES MEMORY FOR CURRENT STRING
		str_length = length(new_s.str) + 2;

		if (str_length > MAX_STRING_LENGTH)
		{
			str = new char[MAX_STRING_LENGTH + 1];
			strncpy(str, new_s.str, MAX_STRING_LENGTH);
			str[MAX_STRING_LENGTH] = '\0';
			return new_s;
			
		}
		else
		{
			str = new char[length(new_s.str) + 2];	//ALLOCATES MEMORY FOR CONCATENATED STRING TO STR
			strcpy(str, new_s.str);	//COPIES ORIGINAL VALUE (FROM COPY) TO STR
			strcat(str, "X");	//CONCATENATES

			return new_s;	//RETURNS ORIGINAL VALUE, STR IS THE MODIFIED VALUE
		}
		


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
	int String::length(const char arr[]) const
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
void display(const String &p);

int main()
{
	
	String s("abcdefghijxxxxxxxxxxx"); // MAX_STRING_LENGTH is 10
	String g("gthu");
	String b("haskjgf");
	s = s + b;
	s[2] = 'Y';

	++s;
	++g;
	display(s); // outputs the string to the screen
	display(g); // outputs the string to the screen
	
	
	
	String::display_count();
	String arra[4];
	String::display_count();
	

	return 0;
}

void display(const String &p)
{
	String d = p;
	int i = 0;
	while (d[i] != '\0')
	{
		std::cout << d[i];
		i++;
	}
	std::cout << "" << std::endl;
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
