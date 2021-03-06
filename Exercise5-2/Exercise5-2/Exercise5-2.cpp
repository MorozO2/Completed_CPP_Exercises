// Exercise 5
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string getVal(string src, const char* tab_b, const char* tag_n);

int main() {
	string page, line, location, temperature;
	ifstream inputFile("weather.xml");

	while (getline(inputFile, line)) {
		page.append(line);
		line.erase();
	}
	//std::cout << page << std::endl;
	// Now page is a string that contains the whole xml page
	location = getVal(page, "<location>", "</location>");
	temperature = getVal(page, "<temp_c>", "</temp_c>");
	// Here you need to write something that finds and 
	// extracts location and temperature from the XML
	// data in the string page and stores them in 
	// the strings location and temperature respectively

	cout << "Location: " << location << endl;
	cout << "Temperature: " << temperature << endl;
	system("pause");
}

string getVal(string src, const char* tag_b, const char* tag_e)
{
	int pos_b = 0;
	int pos_e = 0;
	int str_length = 0;
	string val;
	//string check = tag_b;
	if (src.find(tag_b) != string::npos && src.find(tag_e) != string::npos) //
	{
		pos_b = src.find(tag_b) + strlen(tag_b);
		pos_e = src.find(tag_e);
		str_length = pos_e - pos_b;
		val = src.substr(pos_b, str_length);

		return val;
	}
	else 
	{
		val =  "error";
		return val;
	}
}