#pragma once
#include "Pair.h"

using namespace std;

class Complex_Private : private Pair
{
private:
	Pair pair;

public:

	Complex_Private();
	Complex_Private(double, double);
	Complex_Private(const Complex_Private&);
	~Complex_Private() {};

	using Pair::GetA;
	using Pair::GetB;

	using Pair::SetFirst;
	using Pair::SetSecond;

	Pair GetPair() { return pair; }
	void SetPair(Pair pair) {};
	void Init(Pair pair);
	void Display(Pair& k1, Pair& k2);

	int Diff_1(Pair& k1, Pair& k2);
	int Diff_2(Pair& k1, Pair& k2);

	int Multiply_1(Pair& k1, Pair& k2);
	int Multiply_2(Pair& k1, Pair& k2);

};
