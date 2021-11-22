#include "Complex_Public.h"
#include "Pair.h"
#include "Exception.h"

using namespace std;

Complex_Public::Complex_Public()
{
	double first = 0;
	double second = 0;
	SetFirst(first);
	SetSecond(second);
}
Complex_Public::Complex_Public(double f = 0, double s = 0) //throw(const char*, invalid_argument, Exception, bad_exception&)
{
	double first = f;
	double second = s;
	//if (first < 0 || first >= 200)
	//	throw bad_exception();

	//if (first == 1 && second == 1)
	//	throw Exception("Exception");
	//if (first == 2 && second == 2)
	//	throw invalid_argument("Invalid_argument");

	//if (first == 3 && second == 3)
	//	throw "Error!";
	SetFirst(first);
	SetSecond(second);
}
Complex_Public::Complex_Public(const Complex_Public& r)
{
	double first = r.GetA();
	double second = r.GetB();
	SetFirst(first);
	SetSecond(second);
}

void Complex_Public::Init(Pair pair) { SetPair(pair); }

void Complex_Public::Display(Pair& k1, Pair& k2)
{
	Complex_Public R(0.0, 0.0);
	cout << " (a,b) * (c,d) = (a c * b d , a d + b c)" << "= ";
	cout << "( " << (R.Multiply_1(k1, k2)) << " , " << (R.Multiply_2(k1, k2)) << " )" << endl;

	cout << " (a,b) - (c,d) = (a - c, b - d)" << "=";
	cout << "( " << R.Diff_1(k1, k2) << " , " << R.Diff_2(k1, k2) << " )" << endl;
}

int Complex_Public::Diff_1(Pair& k1, Pair& k2)
{
	return k1.GetA() - k2.GetA();
}

int Complex_Public::Diff_2(Pair& k1, Pair& k2)
{
	return k1.GetB() - k2.GetB();
}

int Complex_Public::Multiply_1(Pair& k1, Pair& k2)
{
	return (k1.GetA() + k2.GetA()) * (k1.GetB() + k2.GetB());
}

int Complex_Public::Multiply_2(Pair& k1, Pair& k2)
{
	return k1.GetA() + k2.GetB() + k1.GetB() + k2.GetA();
}
