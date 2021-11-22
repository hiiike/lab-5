#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Triad 
{
private:
	double first, second, third;
public:
	void SetFirst(double);
	void SetSecond(double);
	void SetThird(double);

	double GetFirst() const;
	double GetSecond() const;
	double GetThird() const;

	Triad();
	Triad(double, double, double);
	Triad(Triad&);

	friend bool operator > (Triad&, Triad&);
	friend bool operator < (Triad&, Triad&);
	friend bool operator == (Triad&, Triad&);
};