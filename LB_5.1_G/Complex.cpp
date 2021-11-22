#include "Complex.h"
#include "Pair.h"

using namespace std;

Complex::Complex()
{
	double first = 0;
	double second = 0;
	SetFirst(first);
	SetSecond(second);
}
Complex::Complex(double f = 0, double s = 0)
{
	double first = f;
	double second = s;
	SetFirst(first);
	SetSecond(second);
}
Complex::Complex(const Complex& r)
{
	double first = r.GetA();
	double second = r.GetB();
	SetFirst(first);
	SetSecond(second);
}

void Complex::Init(Pair pair) { SetPair(pair); }

void Complex::Display(Pair& k1, Pair& k2)
{
	Complex R(0.0, 0.0);
	cout << " (a,b) * (c,d) = (a c * b d , a d + b c)" << "= ";
	cout << "( " << (R.Multiply_1(k1, k2)) << " , " << (R.Multiply_2(k1, k2)) << " )" << endl;

	cout << " (a,b) - (c,d) = (a - c, b - d)" << "=";
	cout << "( " << R.Diff_1(k1, k2) << " , " << R.Diff_2(k1, k2) << " )" << endl;
}

int Complex::Diff_1(Pair& k1, Pair& k2)
{
	return k1.GetA() - k2.GetA();
}

int Complex::Diff_2(Pair& k1, Pair& k2)
{
	return k1.GetB() - k2.GetB();
}

int Complex::Multiply_1(Pair& k1, Pair& k2)
{
	return (k1.GetA() + k2.GetA()) * (k1.GetB() + k2.GetB());
}

int Complex::Multiply_2(Pair& k1, Pair& k2)
{
	return k1.GetA() + k2.GetB() + k1.GetB() + k2.GetA();
}
