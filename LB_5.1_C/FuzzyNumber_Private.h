#pragma once

#include "FuzzyNumber.h"

class FuzzyNumber_Private : private FuzzyNumber {
public:
	FuzzyNumber_Private();
	FuzzyNumber_Private(double, double, double);
	FuzzyNumber_Private(FuzzyNumber_Private&, int);

	using FuzzyNumber::SetX;
	using FuzzyNumber::SetL;
	using FuzzyNumber::SetR;

	using FuzzyNumber::GetX;
	using FuzzyNumber::GetL;
	using FuzzyNumber::GetR;

	FuzzyNumber_Private& operator =(const FuzzyNumber_Private&);
	operator std::string();

	FuzzyNumber_Private& operator ++ ();
	FuzzyNumber_Private& operator -- ();

	FuzzyNumber_Private operator ++ (int);
	FuzzyNumber_Private operator -- (int);

	friend std::ostream& operator << (std::ostream&, const FuzzyNumber_Private&);
	friend std::istream& operator >> (std::istream&, FuzzyNumber_Private&);

	friend FuzzyNumber_Private operator -(FuzzyNumber_Private, FuzzyNumber_Private);
	friend FuzzyNumber_Private operator /(FuzzyNumber_Private, FuzzyNumber_Private);
	static FuzzyNumber_Private Function(FuzzyNumber_Private A, FuzzyNumber_Private B);

};
