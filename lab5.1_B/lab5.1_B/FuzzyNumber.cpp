#include <sstream>
#include "FuzzyNumber.h"
#include "Exception.h"


FuzzyNumber::FuzzyNumber()
{
	x = 0;
	l = 0;
	r = 0;
}
FuzzyNumber::FuzzyNumber(double valuex = 0, double valuel = 0, double valuer = 0)
{

	x = valuex;
	l = valuel;
	r = valuer;
}

FuzzyNumber::FuzzyNumber(FuzzyNumber& obj, int)
{
	x = obj.x;
	l = obj.l;
	r = obj.r;
}

FuzzyNumber& FuzzyNumber::operator =(const FuzzyNumber& obj)
{
	x = obj.x;
	l = obj.l;
	r = obj.r;

	return *this;
}

FuzzyNumber::operator std::string()
{
	std::stringstream sout;
	sout << "\n\nThe value of this objects: ";
	sout << "\nvalue x: " << x;
	sout << "\nvalue l: " << l;
	sout << "\nvalue r: " << r;

	return sout.str();
}


std::ostream& operator << (std::ostream& out, const FuzzyNumber& obj)
{
	out << "\nThe value of the fuzzy number: ( " << obj.x - obj.l << ", " << obj.x << ", " << obj.x + obj.r << " )";
	return out;
}

std::istream& operator >> (std::istream& in, FuzzyNumber& obj) throw(invalid_argument, Exception, bad_exception&)
{
	double a{}, b{}, c{};

	std::cout << "\n\nEnter a value x: "; in >> a;
	std::cout << "\nEnter a value l: "; in >> b;
	std::cout << "\nEnter a value r: "; in >> c;


	if ((a - b) > a)
		throw bad_exception();

	if (a > (a + c))
		throw Exception("Exception");
	if (a == 1 && b == 1 && c == 1)
		throw invalid_argument("Invalid_argument");
	obj.x = a;
	obj.l = b;
	obj.r = c;

	return in;
}

FuzzyNumber& FuzzyNumber::operator ++ ()
{
	++x;
	return *this;
}

FuzzyNumber& FuzzyNumber::operator -- ()
{
	--l;
	return *this;
}

FuzzyNumber FuzzyNumber::operator ++ (int)
{
	FuzzyNumber a(*this);
	r++;
	return a;
}

FuzzyNumber FuzzyNumber::operator -- (int)
{
	FuzzyNumber a(*this);
	x--;
	return a;
}


FuzzyNumber operator -(FuzzyNumber A, FuzzyNumber B)
{
	FuzzyNumber obj_addit(0.0, 0.0, 0.0);
	obj_addit.x = A.x - B.x - A.l - B.l;
	obj_addit.l = A.x - B.x;
	obj_addit.r = A.x - B.x + A.r + B.r;

	return obj_addit;
}

FuzzyNumber operator /(FuzzyNumber A, FuzzyNumber B)
{
	FuzzyNumber obj_multi(0.0, 0.0, 0.0);
	do
	{
		obj_multi.x = 1. / (A.x + A.r);
		obj_multi.l = 1. / A.x;
		obj_multi.r = 1. / (A.x - A.l);

		return obj_multi;
	} while (A.x > 0);
}

FuzzyNumber FuzzyNumber::Function(FuzzyNumber A, FuzzyNumber B)
{
	FuzzyNumber obj_multi_2(0.0, 0.0, 0.0);
	do
	{
		obj_multi_2.x = (A.x - A.l) / (B.x + B.r);
		obj_multi_2.l = A.x / B.x;
		obj_multi_2.r = (A.x + A.r) / (B.x - B.l);

		return obj_multi_2;
	} while (B.x > 0);
}
