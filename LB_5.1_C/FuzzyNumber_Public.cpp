#include <sstream>
#include "FuzzyNumber_Public.h"
#include "Exception.h"

FuzzyNumber_Public::FuzzyNumber_Public() :FuzzyNumber(0, 0, 0) {}

FuzzyNumber_Public::FuzzyNumber_Public(double value_x, double value_l, double value_r) : FuzzyNumber(value_x, value_l, value_r) {}

FuzzyNumber_Public::FuzzyNumber_Public(FuzzyNumber_Public& obj, int) : FuzzyNumber(obj.GetX(), obj.GetL(), obj.GetR()) {}

FuzzyNumber_Public& FuzzyNumber_Public::operator =(const FuzzyNumber_Public& obj) {
	SetX(obj.GetX());
	SetL(obj.GetL());
	SetR(obj.GetR());

	return *this;
}

FuzzyNumber_Public::operator std::string()
{
	std::stringstream sout;
	sout << "The value of this objects: ";
	sout << "\nvalue x: " << GetX();
	sout << "\nvalue l: " << GetL();
	sout << "\nvalue r: " << GetR();

	return sout.str();
}


std::ostream& operator << (std::ostream& out, const FuzzyNumber_Public& obj)
{
	out << "\nThe value of the fuzzy number: ( " << obj.GetX() - obj.GetL() << ", " << obj.GetX() << ", " << obj.GetX() + obj.GetR() << " )";
	return out;
}

std::istream& operator >> (std::istream& in, FuzzyNumber_Public& obj) throw(invalid_argument, Exception, bad_exception&)
{
	double a{}, b{}, c{};

	std::cout << "Enter a value x: "; in >> a;
	std::cout << "\nEnter a value l: "; in >> b;
	std::cout << "\nEnter a value r: "; in >> c;


	if ((a - b) > a)
		throw bad_exception();

	if (a > (a + c))
		throw Exception("Exception");
	if (a == 1 && b == 1 && c == 1)
		throw invalid_argument("Invalid_argument");

	obj.SetX(a);
	obj.SetL(b);
	obj.SetR(c);

	return in;
}

FuzzyNumber_Public& FuzzyNumber_Public::operator ++ ()
{
	SetX(GetX() + 1);
	return *this;
}

FuzzyNumber_Public& FuzzyNumber_Public::operator -- ()
{
	SetL(GetL() - 1);
	return *this;
}

FuzzyNumber_Public FuzzyNumber_Public::operator ++ (int)
{
	FuzzyNumber_Public a(*this);
	SetR(GetR() + 1);
	return a;
}

FuzzyNumber_Public FuzzyNumber_Public::operator -- (int)
{
	FuzzyNumber_Public a(*this);
	SetX(GetX() - 1);
	return a;
}


FuzzyNumber_Public operator -(FuzzyNumber_Public A, FuzzyNumber_Public B)
{
	FuzzyNumber_Public obj_addit(0.0, 0.0, 0.0);
	obj_addit.SetX(A.GetX() - B.GetX() - A.GetL() - B.GetL());
	obj_addit.SetL(A.GetX() - B.GetX());
	obj_addit.SetR(A.GetX() - B.GetX() + A.GetR() + B.GetR());

	return obj_addit;
}

FuzzyNumber_Public operator /(FuzzyNumber_Public A, FuzzyNumber_Public B)
{
	FuzzyNumber_Public obj_multi(0.0, 0.0, 0.0);
	do
	{
		obj_multi.SetX(1. / (A.GetX() + A.GetR()));
		obj_multi.SetL(1. / A.GetX());
		obj_multi.SetR(1. / (A.GetX() - A.GetL()));

		return obj_multi;
	} while (A.GetX() > 0);
}

FuzzyNumber_Public FuzzyNumber_Public::Function(FuzzyNumber_Public A, FuzzyNumber_Public B)
{
	FuzzyNumber_Public obj_multi_2(0.0, 0.0, 0.0);
	do
	{
		obj_multi_2.SetX((A.GetX() - A.GetL()) / (B.GetX() + B.GetR()));
		obj_multi_2.SetL(A.GetX() / B.GetX());
		obj_multi_2.SetR((A.GetX() + A.GetR()) / (B.GetX() - B.GetL()));

		return obj_multi_2;
	} while (B.GetX() > 0);
}
