#pragma once
#include "Pair.h"

using namespace std;

class Complex_Public : public Pair
{
private:
	Pair pair;

public:

	Complex_Public();
	Complex_Public(double, double);
	Complex_Public(const Complex_Public&);
	~Complex_Public() {};

	using Pair::GetA;
	using Pair::GetB;

	using Pair::SetFirst;
	using Pair::SetSecond;

	Pair GetPair() { return pair; }
	void SetPair(Pair pair) {};

	int Diff_1(Pair& k1, Pair& k2);
	int Diff_2(Pair& k1, Pair& k2);

	void Init(Pair pair);
	void Display(Pair& k1, Pair& k2);

	int Multiply_1(Pair& k1, Pair& k2);
	int Multiply_2(Pair& k1, Pair& k2);
};
