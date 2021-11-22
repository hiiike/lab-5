#include <sstream>
#include "FuzzyNumber_Private.h"
#include "Exception.h"

FuzzyNumber_Private::FuzzyNumber_Private() :FuzzyNumber(0, 0, 0) {}

FuzzyNumber_Private::FuzzyNumber_Private(double value_x, double value_l, double value_r) : FuzzyNumber(value_x, value_l, value_r) {}

FuzzyNumber_Private::FuzzyNumber_Private(FuzzyNumber_Private& obj, int) : FuzzyNumber_Private(obj.GetX(), obj.GetL(), obj.GetR()) {}

FuzzyNumber_Private& FuzzyNumber_Private::operator =(const FuzzyNumber_Private& obj) {
	SetX(obj.GetX());
	SetL(obj.GetL());
	SetR(obj.GetR());

	return *this;
}

FuzzyNumber_Private::operator std::string()
{
	std::stringstream sout;
	sout << "\n\nThe value of this objects: ";
	sout << "\nvalue x: " << GetX();
	sout << "\nvalue l: " << GetL();
	sout << "\nvalue r: " << GetR();

	return sout.str();
}

std::ostream& operator << (std::ostream& out, const FuzzyNumber_Private& obj)
{
	out << "\nThe value of the fuzzy number: ( " << obj.GetX() - obj.GetL() << ", " << obj.GetX() << ", " << obj.GetX() + obj.GetR() << " )";
	return out;
}

std::istream& operator >> (std::istream& in, FuzzyNumber_Private& obj) throw(invalid_argument, Exception, bad_exception&)
{
	double a{}, b{}, c{};
	FuzzyNumber_Private::FuzzyNumber F;
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

FuzzyNumber_Private& FuzzyNumber_Private::operator ++ ()
{
	SetX(GetX() + 1);
	return *this;
}

FuzzyNumber_Private& FuzzyNumber_Private::operator -- ()
{
	SetL(GetL() - 1);
	return *this;
}

FuzzyNumber_Private FuzzyNumber_Private::operator ++ (int)
{
	FuzzyNumber_Private a(*this);
	SetR(GetR() + 1);
	return a;
}

FuzzyNumber_Private FuzzyNumber_Private::operator -- (int)
{
	FuzzyNumber_Private a(*this);
	SetX(GetX() - 1);
	return a;
}


FuzzyNumber_Private operator -(FuzzyNumber_Private A, FuzzyNumber_Private B)
{
	FuzzyNumber_Private obj_addit(0.0, 0.0, 0.0);
	obj_addit.SetX(A.GetX() - B.GetX() - A.GetL() - B.GetL());
	obj_addit.SetL(A.GetX() - B.GetX());
	obj_addit.SetR(A.GetX() - B.GetX() + A.GetR() + B.GetR());

	return obj_addit;
}

FuzzyNumber_Private operator /(FuzzyNumber_Private A, FuzzyNumber_Private B)
{
	FuzzyNumber_Private obj_multi(0.0, 0.0, 0.0);
	do
	{
		obj_multi.SetX((1. / (A.GetX() + A.GetR())));
		obj_multi.SetL((1. / (A.GetX())));
		obj_multi.SetR((1. / (A.GetX() - A.GetL())));

		return obj_multi;
	} while (A.GetX() > 0);
}

FuzzyNumber_Private FuzzyNumber_Private::Function(FuzzyNumber_Private A, FuzzyNumber_Private B)
{
	FuzzyNumber_Private obj_multi_2(0.0, 0.0, 0.0);
	do
	{
		obj_multi_2.SetX((A.GetX() - A.GetL()) / (B.GetX() + B.GetR()));
		obj_multi_2.SetL(A.GetX() / B.GetX());
		obj_multi_2.SetR((A.GetX() + A.GetR()) / (B.GetX() - B.GetL()));

		return obj_multi_2;
	} while (B.GetX() > 0);
}
