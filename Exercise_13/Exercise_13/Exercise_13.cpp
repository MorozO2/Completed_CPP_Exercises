// Exercise_13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <algorithm>
#include <memory>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>

using namespace std;

//Definition for exception class
class Exception {
public:
	Exception(const char *explanation0) { explanation = explanation0; }
	const char *what() const { return explanation; }
private:
	const char *explanation;
};


#define N 3

//Class definition for Point
class Point {
	friend ostream& operator<<(ostream &out, const Point &point);
public:
	Point(float x0 = 0.0, float y0 = 0.0);
	~Point();
	float distance(const Point& p2) const;
	float distance() const { return sqrt(x*x + y * y); };
	static int count;
private:
	float x;
	float y;
};
int Point::count = 0;

//-----------------------------------------------------------------
//Implementation of class Point
Point::Point(float x0, float y0) : x(x0), y(y0) {
	count++;
	if (count >= N)
		throw Exception("Does not succeed to create the last apex");
	cout << "Point constructor is done " << (void*)this << endl;
}

Point::~Point() {
	cout << "\nDestructor for Point " << (void*)this << " : ("

		<< x << "," << y << ")" << endl;
}

float Point::distance(const Point& p2) const {
	float deltax = p2.x - x;
	float deltay = p2.y - y;
	return sqrt(deltax*deltax + deltay * deltay);
}


// Friend functions of Point
ostream &operator<<(ostream & out, const Point &point) {
	out << "(" << point.x << "," << point.y << ")";
	return out;
}

float orderDis(unique_ptr<Point>& p1, unique_ptr<Point>& p2);


int main()
{
	try {
		
		vector<unique_ptr<Point>> ps;

		ps.push_back(unique_ptr<Point>(new Point(2,3)));
		ps.push_back(unique_ptr<Point>(new Point(1,4)));
		ps.push_back(unique_ptr<Point>(new Point(2,3)));
		//ps.push_back(new Point(2, 3));
		//ps.push_back(new Point(1, 4));
		//ps.push_back(new Point(2, 2));
		throw Exception("1");
		
		std::sort(ps.begin(), ps.end(), orderDis);

		for (auto i = ps.begin(); i != ps.end(); i++)
		{
			cout << "\n";
			cout << **i << endl;
			//delete *i;
		}
	}
	catch (Exception e) {}
		_CrtDumpMemoryLeaks();
	
}

float orderDis(unique_ptr<Point>& p1, unique_ptr<Point>& p2)
{
	return p1->distance() < p2->distance();
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
