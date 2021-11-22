#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class FuzzyNumber
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
	friend std::istream& operator >> (std::istream&, FuzzyNumber&) throw(const char*, bad_exception&);

	FuzzyNumber& operator ++ ();
	FuzzyNumber& operator -- ();

	FuzzyNumber operator ++ (int);
	FuzzyNumber operator -- (int);

	friend FuzzyNumber operator -(FuzzyNumber, FuzzyNumber);
	friend FuzzyNumber operator /(FuzzyNumber, FuzzyNumber);
	static FuzzyNumber Function(FuzzyNumber A, FuzzyNumber B);

};

