#pragma once

#include "FuzzyNumber.h"

class FuzzyNumber_Public : public FuzzyNumber {
public:
	FuzzyNumber_Public();
	FuzzyNumber_Public(double, double, double);
	FuzzyNumber_Public(FuzzyNumber_Public&, int);

	FuzzyNumber_Public& operator =(const FuzzyNumber_Public&);
	operator std::string();

	FuzzyNumber_Public& operator ++ ();
	FuzzyNumber_Public& operator -- ();

	FuzzyNumber_Public operator ++ (int);
	FuzzyNumber_Public operator -- (int);

	friend FuzzyNumber_Public operator -(FuzzyNumber_Public, FuzzyNumber_Public);
	friend FuzzyNumber_Public operator /(FuzzyNumber_Public, FuzzyNumber_Public);
	static FuzzyNumber_Public Function(FuzzyNumber_Public A, FuzzyNumber_Public B);
};

