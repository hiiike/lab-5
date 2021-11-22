#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "Object.h"
using namespace std;

class FuzzyNumber : public Object
{
private:
	double x;
	double l;
	double r;

public:

	FuzzyNumber();
	FuzzyNumber(double, double, double);
	FuzzyNumber(FuzzyNumber&, int);

	double GetX() const { return x; }
	double GetL() const { return l; }
	double GetR() const { return r; }

	void SetX(double valuex) { x = valuex; }
	void SetL(double valuel) { l = valuel; }
	void SetR(double valuer) { r = valuer; }

	FuzzyNumber& operator =(const FuzzyNumber&);
	operator std::string();

	friend std::ostream& operator << (std::ostream&, const FuzzyNumber&);
	friend std::istream& operator >> (std::istream&, FuzzyNumber&);

	FuzzyNumber& operator ++ ();
	FuzzyNumber& operator -- ();

	FuzzyNumber operator ++ (int);
	FuzzyNumber operator -- (int);

	friend FuzzyNumber operator -(FuzzyNumber, FuzzyNumber);
	friend FuzzyNumber operator /(FuzzyNumber, FuzzyNumber);
	static FuzzyNumber Function(FuzzyNumber A, FuzzyNumber B);

};
