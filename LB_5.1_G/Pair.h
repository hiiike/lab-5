#pragma once
#include <sstream>
#include <string>
#include <iostream>
#include "Object.h"

using namespace std;

class Pair : public Object
{
private:
	double first;
	double second;

public:

	Pair();
	Pair(double, double);
	Pair(const Pair&);
	~Pair();

	double GetA() const { return first; }
	double GetB() const { return second; }
	void SetFirst(double D) {};
	void SetSecond(double V) {};
	bool Init(double D, double V);

	Pair& operator = (const Pair&);
	operator string() const;
	friend ostream& operator << (ostream&, const Pair&);
	friend istream& operator >> (istream&, Pair&);

	friend Pair operator + (const Pair&, const Pair&);
};
